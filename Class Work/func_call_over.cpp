#include<iostream>
using namespace std;
class Func
{
    private: int s;
    public:
            Func(int x)
            {
                s=x;
            }
            int  operator()(int v)
            {
                s=s+v;
                return v;
            }
            void display()
            {
                cout<<s<<endl;
            }
};
int main()
{
    Func ob(5);
    int x=ob(10);
    ob.display();
    cout<<"Value returned "<<x;
    return 0;
}