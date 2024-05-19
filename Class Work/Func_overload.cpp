#include<iostream>
using namespace std;
void sum(int ,int,int);
//void sum(float,float);
//void sum(float,int);

int main()
{
    int x,y,z;
    float a,b;
    cout<<"Enter 3 numbers ";
    cin>>x>>y>>z;
    cout<<"Enter 2 decimal number ";
    cin>>a>>b;
    sum(x,y);
    /*sum(a,b);
    sum(a,x);*/
    return 0;
}
void sum(int a,int b,int c=5)
{
    int sum;
    sum=a+b+c;
    cout<<"Sum is: "<<sum;
}
/*void sum(float a,float b)
{
    float s;
    s=a+b;
    cout<<"\nSum is: "<<s;
}
void sum(float x,int a)
{
    float sm;
    sm=x+a;
    cout<<"\nSum is: "<<sm;
}*/