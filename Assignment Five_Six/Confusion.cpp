#include<iostream>
using namespace std;

class Metre
{
    int mt;
    float cm;
    public:
        Metre(float a)
        {
            cm=a;
            mt=0;
        }
        void display()
        {
            mt=cm/100;
            cm-=(mt*100);
            cout<<"\nTotal distance in metre and centimetre : "<<mt<<"m "<<cm<<"cm\n";
        }
};

class Distance
{
    float feet;
    int inch;
    public:
        Distance()
        {
            feet=0;
            inch=0;
        }
        Distance(float x)
        {
            feet=x;
        }
        Distance(int y)
        {
            inch=y;
        }
        Distance(float x,int y)
        {
            feet=x;
            inch=y;
        }
        Distance(Distance &obj)
        {
            feet=obj.feet;
            inch=obj.inch;
        }
        void input()
        {
            cout<<"Enter the feet distance : ";
            cin>>feet;
            cout<<"Enter the inches distance : ";
            cin>>inch;
        }
        void display()
        {
            int a=inch/12;
            feet+=a;
            inch=inch%12;
            cout<<"Total Distance = "<<feet<<" feet "<<inch<<" inches";
        }
        Distance operator +(Distance obj)
        {
            Distance temp;
            temp.feet=feet+obj.feet;
            temp.inch=inch+obj.inch;
            return temp;
        }
        operator int()
        {
            inch=(feet*12)+inch;
            return inch;
        }
        operator Metre()
        {
            float a=inch*2.54;
            return Metre(a);
        }
};

int main()
{
    Distance A,B;
    cout<<"Distance 1 :\n-----------\n";
    A.input();
    
    cout<<"\nDistance 2 :\n-----------\n";
    B.input();
    
    Distance C;
    C=A+B;                //C is shallow copy...Firing default copy assignment operator
    cout<<"\nAfter Adding the 2 distances :---   \n\n";     
    C.display();
    
    int x=(int)(C);
    cout<<"\nTotal distance in inches = "<<x<<" inches";

    Metre D=C;             //compiler somehow implicitly converting so didnt write whole code
    D.display();
    
    return 0;
}