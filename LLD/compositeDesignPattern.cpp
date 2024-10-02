#include <iostream>
#include <vector>
#include <string>
using namespace std;

// calculator design pattern

class FileSystem
{

    public:
    virtual void ls(int) = 0;

};


class File : public FileSystem
{
    string name;

    public:

    File(string filename) : name(filename){}
    void ls(int tab)
    {
        int k = tab;
        while(k--)
        {
            cout<<"---";
        }
        cout<<"File name: "<<name<<"\n";
    }
};

class Directory : public FileSystem
{
    string name;
    vector<FileSystem * >directories;

    public:

    Directory(string directoryname) : name(directoryname)
    {

    }

    void addDirectory(FileSystem * directory)
    {
        directories.push_back(directory);
    }

    void ls(int tab)
    {     int k = tab;
          while(k--)
          {
            cout<<"---";
          }
          cout<<"Directory name :"<<name<<"\n";

          for(auto directory : directories)
          {
            directory->ls(tab + 1);
          }
    }
};

int main()
{
      File f1("Boarder");
      File f2("Hangama");

      Directory d1("Movie");
      Directory d2("Comedy Movie");


      d1.addDirectory(&d2);
      d2.addDirectory(&f2);
      d1.addDirectory(&f1);


     d1.ls(0);

     return 0;
      
}