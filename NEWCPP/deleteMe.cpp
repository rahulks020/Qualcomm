import groovy.json.JsonOutput

ArrayList header = [[maskValue: false, name: 'Content-Type', value: 'application/json']]
pipeline {
    agent {
        label 'Windows && APEX7'
    }

    triggers {
        cron 'H 19 * * *'
    }

    environment{
        InstallerPath="C:\\Scripts"
        CredentialsId='f2b8724d-35d4-4b1b-9ba0-0afdb357436f'
        Product='Lahaina.LA.2.0'
        MetaBuild= '\\\\apex-qcat\\Scripts\\QCAT_Testlogs\\ContentsXML'
        Branch='APEX7_Sanity'
        Variant='RegressionTest'
        msBuildPath='C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\Msbuild\\Current\\Bin\\MSBuild.exe'
        outputPath='\\\\scl-cps-adm5\\QPM_GNSSAPEX7'
    }

    parameters{
        string defaultValue:"*/master", description:"Git branch", name:"GitBranch"
        booleanParam defaultValue: false, description: 'Override Auto Fetching Version info from QPM', name:'OverideVersionString'
        string description:'Apex7 version to be published(if override flag is checked)', name: 'Version', trim: true
        booleanParam defaultValue: true, description: '', name: 'Publish'
        booleanParam defaultValue: true, description: '', name: 'Verbose'
        booleanParam defaultValue: true, description: '', name: 'CleanBuild'
        string defaultValue: 'Builds\\Win32\\Release', name: 'OutputDir', trim: true
        booleanParam defaultValue: true, description: '', name: 'Branching'
        string defaultValue: 'APEX', name: 'AppName', trim: true
        choice choices: ['release', 'nightly'], name: 'BuildType'
        choice choices: ['release', 'debug'], name: 'BuildConfig'
        booleanParam defaultValue: true, description: '', name: 'Compile'
        booleanParam defaultValue: false, description: '', name: 'CleanWorkspaceAfterbuild'
    }

    stages {
        
        stage('Trigger a new Job for building container and publishing to Axiom'){
            steps{
                timeout(45) {
                    string jobParameters = "{\"Name\":\"apex7_windows\",\"Id\":73,\"ExecutionEnvironment\":1,\"ECRRepoName\":\"apex7_windows\",\"SkipDbUpdate\":true,\"SoftwarePackages\":[{\"Name\":\"APEX7\",\"Id\":6,\"Type\":0,\"ReleaseBranch\":\"staging\",\"Version\":${Version},},{\"Name\":\"QPM\",\"Id\":3,\"Type\":1,\"ReleaseBranch\":null,\"Version\":\"3.3.0.94.2\",}]}"
                    build job: 'ProdBuildContainer',
                          parameters: [
                            string(name: 'Branch', value: '*/master'),
                            string(name: 'BuildVersion', value: '1.0.0'),
                            booleanParam(name: 'WindowsContainer', value: true),
                            string(name: 'DockerFile', value: 'Apex7Workflow/Dockerfiles/Dockerfile.windows'),
                            text(name: 'BuildParams', value: jobParameters)]
                }
            }
        }
    
        stage('Trigger Sanity jobs in Axiom Production for APEX'){
            steps{
                timeout(2) {
                    println "Trigger Sanity jobs in Axiom Production for APEX"
                    script {
                        Map requestBody  = [Product: Product, CiSystem:'Jenkins', CIUrl:RUN_DISPLAY_URL, MetaBuild: [Windows: MetaBuild, Linux:''], Branch: Branch, Variant: Variant]
                        String urlEndPoint = "https://api.axiom.qualcomm.com/events?\$basic=axiomppsvc"

                        println(JsonOutput.toJson(requestBody))
    
                        def response = httpRequest customHeaders: header,
                                      httpMode: 'POST',
                                      ignoreSslErrors: true,
                                      requestBody: JsonOutput.toJson(requestBody),
                                      url: urlEndPoint,
                                      wrapAsMultipart: false,
                                      validResponseCodes: '200'

                        Map content =  readJSON text: response.content
                        eventurl = content['url']
                    }
                }
            }
        }
         stage('Copy for gnss') {
                steps {
                        withCredentials([usernamePassword(credentialsId: 'AxiomJKUser', passwordVariable: 'Pswd', usernameVariable: 'Usrname')])  {
                            script{
                                def Pswd=Pswd.replaceAll("%", "%%")
                                bat("net use ${outputPath} /user:${Usrname} ${Pswd}")
                            }
                            bat("((robocopy QCAT7\\v7\\lib ${outputPath}) ^& IF %ERRORLEVEL% LSS 8 EXIT /B 0)")
                            bat("((robocopy . ${outputPath} *.h /S) ^& IF %ERRORLEVEL% LSS 8 EXIT /B 0)")
                            bat("((robocopy QCAT7\\v7 ${outputPath}\\Installer  /IF *Windows-x86.exe) ^& IF %ERRORLEVEL% LSS 8 EXIT /B 0)")
                        }
            }
        }

    }    
   
    post {
        always {
            script{
                if(CleanWorkspaceAfterbuild.toBoolean())
                {
                    cleanWs cleanWhenAborted: false, cleanWhenFailure: false, cleanWhenUnstable: false, notFailBuild: true
                }
                else
                {
                    println "Not cleaning up the workspace"
                }
                bat("net use ${outputPath} /delete")
            }
        }
        success{
            emailext body:"APEX7 Build successful for Version ${Version} - ${RUN_DISPLAY_URL}  and  Trigged a Axiom Event ${eventurl}", from:'CloudDeployments@qti.qualcomm.com', replyTo:'rsharm@qti.qualcomm.com;rsharm@qti.qualcomm.com', subject:"APEX7 Build successful - ${BUILD_NUMBER}", to:'rsharm@qualcomm.com;rsharm@qti.qualcomm.com'
        }
        failure{
            emailext attachLog: true, body:"APEX7 Build Failed - ${RUN_DISPLAY_URL}", from:'CloudDeployments@qti.qualcomm.com', replyTo:'cloud.jenkins.notification@qti.qualcomm.com', subject:"APEX7 Build Failed - ${BUILD_NUMBER}", to:'rsharm@qualcomm.com;rsharm@qti.qualcomm.com;cc:cloud.jenkins.notification@qti.qualcomm.com'
        }
        aborted{
            emailext attachLog: true, body:"APEX7 Build Aborted - ${RUN_DISPLAY_URL}", from:'CloudDeployments@qti.qualcomm.com', replyTo:'cloud.jenkins.notification@qti.qualcomm.com', subject:"APEX7 Build Aborted - ${BUILD_NUMBER}", to:'rsharm@qualcomm.com;rsharm@qti.qualcomm.com;cc:cloud.jenkins.notification@qti.qualcomm.com'
        }
    }
 }