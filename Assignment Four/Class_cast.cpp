#include<iostream>
using namespace std;
class Minute;
class Hour
{
    int hr;
    public: Hour(int h1)               //REQUIRED FOR HOUR TO MINUTES CONVERSION
            {
                hr=h1;
            }
            int get1()                  //REQUIRED FOR HOUR TO MINUTES CONVERSION 
            {
                return hr;
            }
            Hour(Minute &obj);           //REQUIRED FOR MINUTES TO HOUR CONVERSION
                                         //CONSTRUCTOR CASTING DONE IN DESTINATION CLASS
            void display()
            {
                cout<<hr<<"hour\n";
            }
};
class Minute
{
    int m;
    public: Minute(int min)    //REQUIRED FOR MINUTES TO HOURS AS FOR THE OTHER WAY ROUND THERE IS
            {                  //ALREADY ANOTHER CONSTRUCTOR
                m=min;
            }
            int get()           //REQUIRED FOR MINUTES TO HOUR CONVERSION
            {
                return m;
            }
            Minute(Hour&obj)    //REQUIRED WHEN CONVERTING HOUR TO MINUTES 
            {                   //CONSTRUCTOR CASTING DONE IN DESTINATION CLASS
                int h=obj.get1();
                m=h*60;

            }
            void disp()
            {
                cout<<m<<"minutes\n";
            }
};
int main()
{
    //MINUTE TO OBJECT
    cout<<"MINUTE TO HOUR\n";
    Minute A(60);
    Hour B=(Hour)A;
    B.display();

    //HOUR TO MINUTES
    cout<<"HOUR TO MINUTES\n";
    Hour C(1);
    Minute D=(Minute)C;
    D.disp();
    return 0;
}
Hour::Hour(Minute &obj)        //MINUTES TO HOUR , SINCE WROTE HOUR CLASS BEFORE SO HAVING TO WRITE THIS LAST
        {
            int m=obj.get();
            hr=m/60;
        }