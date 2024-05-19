/*Date difference 14.02.1973 and 11.10.2003 is 30yrs 7 months 25 days*/


#include<iostream>
using namespace std;
class Date
{
    int d,m,y;
    public:
            Date()
            {
                d=0;
                m=0;
                y=0;
            }
            Date(int da,int mo,int ye)
            {
                d=da;
                m=mo;
                y=ye;
            }
            Date operator -(Date obj)
            {
                Date t;
            
                t.d=d-obj.d;
                t.m=m-obj.m;
                t.y=y-obj.y;

                if(t.d<0 && t.m>=0)
                {
                    if(t.m!=0)
                        t.m--; //since unable to complete total cycle to exact date so total month is incomplete
                    else
                    {
                        t.y--;
                        t.m=11+t.m;
                    }
                    switch(obj.m)
                    {
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                        case 12:
                                t.d=31+t.d;
                                break;
                        case 2:
                                cout<<t.d;
                                if(obj.y%400==0)
                                    t.d=29+t.d;
                                else
                                    t.d=28+t.d;
                                    break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                                t.d=30+t.d;
                    }
                } //end of date 
                else if((t.d<0) && (t.m<0))
                {
                    if(t.y!=0)
                        t.y--;
                    t.m=11+t.m;    //Whenever whichever is negative 1 is diducted from the next entity
                    switch(obj.m)
                    {
                        case 1:
                        case 3:
                        case 5:
                        case 7:
                        case 8:
                        case 10:
                        case 12:
                                t.d=31+t.d;
                                break;
                        case 2:
                                if(obj.y%400==0)
                                    t.d=29+t.d;
                                else
                                    t.d=28+t.d;
                                break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                                t.d=30+t.d;  
                    }
                }  // end of date and month
                else if(t.m<0)
                {
                    t.y--;
                    t.m=12+t.m;
                }
                return t;
            }
            void display()
            {
                cout<<"Difference : "<<d<<" days "<<m<<"months and "<<y<<"Years"<<endl;
            }
            
};
int main()
{
    Date C;
    int d1,m1,y1,d2,m2,y2;
    cout<<"__________________________________________\n";
    cout<<"DATE 1 :\nEnter the date,month and year : ";
    cin>>d1>>m1>>y1;
    
    cout<<"__________________________________________\n";
    cout<<"DATE 2 :\nEnter the date,month and year : ";
    cin>>d2>>m2>>y2;

        Date A(d1,m1,y1);
        Date B(d2,m2,y2);
        if(y1>y2)
            C=A-B;
        else
            C=B-A;
    cout<<"__________________________________________\n";
    C.display();
    cout<<"__________________________________________\n";
    return 0;
}