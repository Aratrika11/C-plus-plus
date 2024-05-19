#include<iostream>
using namespace std;

class Cal
{
    int sum,sub,prod;
    float div;
    public: Cal()
    {
        sum=sub=prod=0;
        div=0.0;
    }
    void add(int x,int y)
    {
        sum=x+y;
        cout<<"Sum= "<<sum;
    }
    void subs(int x,int y)
    {
        sub=y-x;
        cout<<"Difference= "<<sub;
    }
    void pro(int x,int y)
    {
        prod=x*y;
        cout<<"Product= "<<prod;
    }
    void divide(int x,int y)
    {
        div=y/x;
        cout<<"division= "<<div;
    }
};
int main()
{
    int a,b,k;
    cout<<"Enter two numbers";
    cin>>a>>b;
    cout<<"Enter 1 for add, 2 for substract , 3 for product , 4 for divide\n";
    cin>>k;

    Cal obj;
    switch(k)
    {
        case 1: obj.add(a,b);
                break;
        case 2: obj.subs(a,b);
                break;
        case 3: obj.pro(a,b);
                break;
        case 4: obj.divide(a,b);
                break;
        default:cout<<"Wrong choice";
    }
    return 0;
}
