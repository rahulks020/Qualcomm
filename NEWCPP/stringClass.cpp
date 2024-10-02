#include <iostream>
#include <cstring>

class String
{
    char * data;
    int len;

    public:
    //default
    String() : data(nullptr), len(0) {}

    //parametrised consructor
    String(const char * str)
    {
        len = std::strlen(str);
        data = new char[len + 1];
        std::strcpy(data, str);
    }

    // copy constructor
    String(const String & other)
    {
        len = other.len;
        data = new char[len];
        std::strcpy(data, other.data);
    }

     // Move constructor
    String(String&& other) noexcept : data(other.data), len(other.len) {
        other.data = nullptr;
        other.len= 0;
    }

   // copy assignement operator
    String & operator=(const String & other)
    {
        if(this == &other) {
            //std::cout<<"copying to itself";

            return *this;
        }

        delete [] data;

        len = other.len;
        data = new char[len + 1];
        std::strcpy(data, other.data);
        
        return *this;

    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        len = other.len;

        other.data = nullptr;
        other.len = 0;

        return *this;
    }

    String operator+(const String& other) const 
    {
        String newString;
        newString.len = len + other.len;
        newString.data = new char[newString.len + 1];
        strcpy(newString.data, data);
        strcat(newString.data, other.data);
        return newString;
    }

    friend std::ostream& operator<<(std::ostream & os, String & str)
    {
          if(str.data)
          {
            os<<str.data;
          }
          else{
            os<<"its pointing to nulptr\n";
          }

          return os;
    }

    // Overload the >> operator for input
    // friend std::istream& operator>>(std::istream& is, String& str) {
    //     char buffer[1000];
    //     is >> buffer;
    //     str.len = std::strlen(buffer);
    //     delete[] str.data;
    //     str.data = new char[str.len + 1];
    //     std::strcpy(str.data, buffer);
    //     return is;
    // } 

    friend std::istream& operator>>(std::istream& is, String & str)
    {
        char buffer[100];
        is >> buffer;
        str.len = std::strlen(buffer);
        delete [] str.data;
        str.data = new char[str.len+ 1];
        std::strcpy(str.data, buffer);

        return is;

    }
};

int main()
{

    std::cout<<"Hello world\n";
    String str1;                  // default constructor
    String str2("Hello world");   // parametrized constructor
    std::cout << " str2: "<<str2;         
    
    str1 = str2; //  copy assignement operator       // assigns the contents of one object to another        
    std::cout << " str1: "<<str1;

    String str3(str2);  // copy constructor  same as  str4 = str3             creates a new  objects as a copy of exisiting one.
    std::cout << " str3: "<<str3;

    String str4 = str3; // copy constructor same as str3(str2)           creates a new  objects as a copy of exisiting one
    std::cout << " str4: "<<str4;

    //str4 = str4;

    //std::cin>>str4;
    std::cout << " Str4: "<<str4;

    String str5("Sharma");
    std::cout<<" Str5: "<<str5;

    //Move obj str5 to str6 using move constructor
    String str6 = std::move(str5);    // it makes use of move semantics to transfer the ownership of the already created object to the new object without creating extra copies
    std::cout<<" Str6: "<<str6;
    std::cout<<" Str5: "<<str5;

    // Move str6 to str5 using move assignment
    str5 = std::move(str6);
    std::cout<<" Str5: "<<str5;
    std::cout<<" Str6: "<<str6;

    std::cin>>str6;
    std::cout<<"New Str6: "<<str6;

    String snew = str6 + str1;
    std::cout<<"Str Newz: "<<snew;

    return 0;
}