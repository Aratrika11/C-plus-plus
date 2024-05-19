#include<iostream>
using namespace std;

class Addition
{
    public:
            int x,y;
            Addition()
            {
                x=4;
                y=5;
            }
            Addition(int a,int b)
            {
                x=a;
                y=b;
            }
            void add()
            {
                cout<<x+y;
            }
};
class Why:public Addition
{
    public:
            void display()
            {
                cout<<x;
            }
};
int main()
{
    Why obj;
    obj.add();
    obj.display();
    return 0;
}