#include<iostream>
using namespace std;

class Convert
{
    int x;
    public:Convert(int y)
           {
            x=y;
           }
           void display()
           {
            cout<<x;
           }
};

int main()
{
    int da=10;
    Convert obj=(Convert) da;
    obj.display();
    return 0;
}