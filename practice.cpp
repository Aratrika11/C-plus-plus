/*WAP to convert year in to months and vice - versa using class to class conversion.
Type Casting method*/
/* #include<iostream>
using namespace std;

class Month;
class Year
{
    int yr;
    public:
            Year(int y)
            {
                yr=y;
            }
            operator Month();
            void display()
            {
                cout<<yr<<" yrs";
            }
};
class Month
{
    int mn;
    public:
            Month(int m)
            {
                mn=m;
            }
            void display()
            {
                cout<<mn<<" months";
            }
            operator Year();
};
int main()
{
    cout<<"YEAR TO MONTH\n";
    Year obj(3);
    Month ob=(Month)obj;
    ob.display();

    cout<<"\nMONTH TO YEAR\n";
    Month obk(24);
    Year obn=(Year)obk;
    obn.display();
    return 0;
}
Year::operator Month()
        {
            int mo=yr*12;
            return Month(mo);
        }
Month::operator Year()
        {
            int y=mn/12;
            return Year(y);
        }*/

/*WAP to convert year into month and vice versa using CLass to CLass conversion
Constructor method*/

#include<iostream>
using namespace std;

class Month;
class Year
{
    int yr;
    public:
            Year(int y)
            {
                yr=y;
            }
            void display()
            {
                cout<<yr<<" yrs";
            }
            int get()
            {
                return yr;
            }
            Year(Month &obj);
};
class Month
{
    int mn;
    public:
            Month(int m)
            {
                mn=m;
            }
            int get()
            {
                return mn;
            }
            void display()
            {
                cout<<mn<<" months";
            }
            Month(Year &obj);
};
int main()
{
    cout<<"MONTHS TO YEARS\n";
    Month obj(36);
    Year ob=(Year)obj;
    ob.display();

    cout<<"\nYEARS TO MONTHS \n";
    Year obk(4);
    Month obn=(Month)obk;
    obn.display();
    return 0;
}
Year::Year(Month &obj)
        {
            int mo=obj.get();
            yr=mo/12;
        }
Month::Month(Year &obj)
        {
            int y=obj.get();
            mn=y*12;
        }