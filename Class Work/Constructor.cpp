#include<iostream>
using namespace std;

class Test
{
    int a,b,age;
    public: Test()
    {
        cout<<"Default Constructor ";
        a=0,b=0;
        age=0;
    }
    public: Test(int x)
    {
        cout<<"Parameterized Constructor ";
        age=x;
    }
    void print()
    {
        cout<<a<<b<<" ";
        cout<<age;

    }
};
int main()
{
    //Test ob;
    //ob.print();
    Test obj(5);
    obj.print();
    return 0;

}