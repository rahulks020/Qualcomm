#include <iostream>
#include <vector>
#include <map>
using namespace std;

// chain of responsibity  + observer state

class LogObserver
{
   public:
   virtual void log(string msg) = 0;
   
};

class ConsoleLogger : public LogObserver
{
   public:
   void log(string msg) override
   {
    cout<<"Console Mag: "<<msg<<"\n";
   }
};

class FileLogger : public LogObserver
{
   public:
   void log(string msg) override
   {
    cout<<"File Msg: "<<msg<<"\n";
   }
};



class LogSubject
{
    map<int, vector<LogObserver*> >m;

    public:
    void addObserves(int level, LogObserver * obserser)
    {
        m[level].push_back(obserser);
    }

    void notify(int level, string msg)
    {
        if(m.find(level) != m.end())
        {
            for(auto entry = 0; entry !=  m[level].size(); entry++)
            {
                LogObserver * obj = m[level][entry];
                //cout<<msg<<"\n";
                obj->log(msg);
            }
        }
           
    }
    
};

class AbrstractLogger
{
    protected:
    int level;
    AbrstractLogger * abstractloghger;

    public:
    AbrstractLogger()
    {
        abstractloghger = NULL;
        level = 0; 
    }

    virtual void display(string msg, LogSubject *) = 0;

    void setNextLevelLogging(AbrstractLogger * abstractLogger)
    {
        this->abstractloghger = abstractLogger;
    }

    void logMessage(int lvl, string msg, LogSubject * logSubject)
    {
        if(this->level <= lvl)
        {
            display(msg, logSubject);
        }

        if(abstractloghger != NULL)
        {

            abstractloghger->logMessage(lvl, msg, logSubject);
        }
    }

    
};

class InfoLogger : public AbrstractLogger
{
     public: 
     InfoLogger(int level)
     {
        this->level = level;
     }

     void display(string msg, LogSubject * logSubject) override
     {
         //cout<<"INFO:" << msg <<"\n";
         logSubject->notify(1, msg);
     }
};

class DebugLogger : public AbrstractLogger
{
     public: 
     DebugLogger(int level)
     {
        this->level = level;
     }
     void display(string msg, LogSubject * logSubject) override
     {
         //cout<<"INFO:" << msg <<"\n";
         logSubject->notify(2, msg);
     }
};

class ErrorLogger : public AbrstractLogger
{
     public: 
     ErrorLogger(int level)
     {
        this->level = level;
     }

     void display(string msg, LogSubject * logSubject) override
     {
         //cout<<"INFO:" << msg <<"\n";
         logSubject->notify(3, msg);
     }
};

class LogManager
{

     public:
     static AbrstractLogger * buildChainOfLogger()
     {
        AbrstractLogger * infoLogger = new InfoLogger(1);
        AbrstractLogger * debugLogger = new DebugLogger(2);
        AbrstractLogger * errorLogger = new ErrorLogger(3);


        infoLogger->setNextLevelLogging(debugLogger);
        debugLogger->setNextLevelLogging(errorLogger);

        return infoLogger;
     }

     static LogSubject * buildLogSubject()
     {
        LogSubject * logSubject = new LogSubject();

        LogObserver * consoleLogger = new ConsoleLogger();
        LogObserver * fileLogger = new FileLogger();

        logSubject->addObserves(1, consoleLogger);
        logSubject->addObserves(2, consoleLogger);
        logSubject->addObserves(1, fileLogger);

        return logSubject;
     }


};


class Logger
{
    static Logger * logger;
    static AbrstractLogger * chainOfLogger;
    static LogSubject * chainOfSubject;

    Logger (){};

    public:
    
    static Logger * getInstace()
    {
         if(logger == NULL)
         {
            logger  = new  Logger();
            chainOfLogger = LogManager::buildChainOfLogger();
            chainOfSubject  = LogManager::buildLogSubject();

         }

         return logger;
    }

    void createLog(int level, string message, LogSubject * logSubject )
    {
        chainOfLogger->logMessage(level, message, logSubject);
    }

    void info(string msg)
    {
        createLog(1, msg, chainOfSubject);
    }

    void debug(string msg)
    {
        createLog(2, msg, chainOfSubject);
    }

    void error(string msg)
    {
        createLog(3, msg, chainOfSubject);
    }

};

Logger * Logger::logger = NULL;
AbrstractLogger * Logger::chainOfLogger = NULL;
LogSubject * Logger::chainOfSubject = NULL;
 
int main()
{
    cout<<"HELLO World!\n";

    Logger * logger = Logger::getInstace();

    logger->info("Loger Info");

    // logger->debug("Loger Info");

    // logger->error("Loger Info");

    return 0;
}
