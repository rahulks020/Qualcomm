#include <iostream>
using namespace std;

class TwoDArray
{

    int rows;
    int cols;
    int **arr;

    public:

    TwoDArray(int row, int col) : rows(row), cols(col)
    {
        arr = new int*[rows];

        for(int i = 0; i < cols; i++)
        {
            arr[i] = new int[cols];
        }
    }

    void setData(int r, int c, int data)
    {
        arr[r][c] = data;
    }

    int getData(int r, int c)
    {
        return arr[r][c];
    }

    ~TwoDArray()
    {
        for(int i = 0; i < rows; i++)
        {
            delete [] arr[i];
        }

        delete[] arr;
    }

};

int main()
{
    TwoDArray arr(2, 3);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr.setData(i, j, i * 10 + j);

            
        }
    }


    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<arr.getData(i, j)<<" ";

            
        }

        cout<<"\n";
    }

    return 0;
}