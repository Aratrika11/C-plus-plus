//converting user defined type to user defined type by Type Casting Overloading

#include<iostream>
using namespace std;
class Hour                   //DESTINATION CLASS
{
    int hr;
    public: Hour(int h1)
            {
                hr=h1;
            }
            void display()
            {
                cout<<hr;
            }
};

class Minute                    //SOURCE CLASS
{
    int m;
    public:Minute(int min)
           {
            m=min;
           }
           operator Hour()            //overloading function 
           {
            int h1=m/60;
            return Hour(h1);
           }
};
int main()
{
    Minute obj(60);
    Hour ob=(Hour)obj;
    ob.display();
    return 0;
}