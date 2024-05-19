#include<iostream>
using namespace std;

class Convert
{
    int x;
    public: Convert(int y)
            {
                x=y;
            }
            operator int()
            {
                return x;
            }
};

int main()
{
    Convert obj(5);
    //int y=(int)obj;
    //OR
    int y= static_cast<int>(obj);
    cout<<y;
    return 0;
}