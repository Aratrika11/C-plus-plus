#include<iostream>
using namespace std;

class Dummy
{
    private: int x, y;
    public: 
            Dummy(int a,int b)
            {
                x=a;
                y=b;
            }
            void set(int x,int y)
            {
                this->x=x;
                this->y=y;   //left side member right side local
            }
            void display()
            {
                cout<<x<<endl;
                cout<<y<<endl;
            }
};
int main()
{
    Dummy obj(5,6);
    obj.display();
    obj.set(11,22);
    obj.display();
    return 0;
}