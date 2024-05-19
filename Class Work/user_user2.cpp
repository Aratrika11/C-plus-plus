//Converting from user defined to user defined type using Constructor

#include<iostream>
using namespace std;
class Minute;
/*class Minute                                  
{
    int m;
    public:Minute(int min)
           {
            m=min;
           }
           int get()
           {
            return m;
           }
};*/
class Hour                           //or write the minute class first then the Hour class 
{                                    //in that case 
    int hr;                          
    public:Hour(int h1)
           {
            hr=h1;
           }
           void display()
           {
            cout<<hr;
           }
           Hour(Minute &obj) ;          //the whole function definition is given here no need to 
};                                    //forward declarartion
class Minute                                  
{
    int m;
    public:Minute(int min)
           {
            m=min;
           }
           int get()
           {
            return m;
           }
};

Hour::Hour(Minute &obj)
      {
        int m=obj.get();
        hr=m/60;
      }

int main()
{
    Minute obj(60);
    Hour ob=(Hour)obj;
    ob.display();
    return 0;
}