#include<iostream>
#include<vector>

using namespace std;

enum pieceType { X, O};

class base
{
    pieceType p;
    public:
    base(pieceType x) : p (x) 
    {
        cout<<"base\n";

        cout<<p<<"\n";
    }
};

class child1 : public base
{
    public:
    child1() : base(X)
    {

        cout<<"child1\n";

        cout<<"X"<<"\n";
    }

};

class child2 : public base
{
    public:
    child2() : base(O)
    {

        cout<<"child2\n";

        cout<<"O"<<"\n";
    }

};

class Board
{
    int size;
    vector<vector<base> >board;

    public:
    Board(int n):size(n)
    {
        for(int i = 0; i < n; i++)
        {

            vector<base>v;

            for(int j = 0; j < n; j++)
            {
                v.push_back(NULL);
            }
            board.push_back(v);
        }
    }
};

int main()
{

    child1 c1 = child1();
    
    child2 c2 = child2();
    return 0;
}



