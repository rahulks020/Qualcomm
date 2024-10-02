#include<iostream>
#include<map>
#include<list>
using namespace std;

// class LRU
// {
//     list<int>lt;
//     map<int, list<int>::iterator>mp;
//     int capacity;

//     public:

//     LRU(int size)
//     {
//         capacity  = size;
//     }

//     void push(int val)
//     {
//           if(mp.find(val) != mp.end())
//           {
//             lt.erase(mp[val]);
//              mp.erase(val);
//           }

//           if(lt.size() == capacity)
//           {
//              int key = lt.back();
//              lt.pop_back();
//              mp.erase(key);
//           }

//           lt.push_front(val);
//           mp[val] = lt.begin(); 
          
//     }

//     void show()
//     {
//         for(auto i = lt.begin(); i != lt.end(); i++)
//         {
//             cout<<*i<<" ";
//         }

       
//     }


// };

// int main()
// {
//          LRU L(3);

//          L.push(1);
//          L.push(2);
//          L.push(3);

//          L.show();

//          L.push(2);

//          L.show();

//          return 0;
// }

class LRU
{
    list<int>lt;
    map<int, list<int>::iterator>mp;
    int capacity;
    public:

    LRU (int size):capacity(size){}

    void push(int key)
    {
          if(mp.find(key) != mp.end())
          {
              lt.erase(mp[key]);
              mp.erase(key);
          }

          if(capacity == lt.size())
          {
            int temp_key = lt.back();
            lt.pop_back();
            mp.erase(temp_key);
          }

          lt.push_front(key);
          mp[key] = lt.begin();
    }

    void show()
    {
        for(auto i : lt)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    
};

int main()
{
    LRU lru(4);

    lru.push(9);
    lru.show();  // 9

    lru.push(8);
    lru.show(); // 8 9

    lru.push(7);
    lru.show();  // 7 8 9

    lru.push(8);
    lru.show(); // 8 7 9

    lru.push(0);  // 0 8 7 9
    lru.show();

    lru.push(1);  // 1 0 8 7
    lru.show();

    return 0;
}