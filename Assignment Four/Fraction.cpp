#include<iostream>
using namespace std;

class Fraction
{
    int nu,de;
    public: Fraction()
            {
                nu=0;
                de=0;
            }
            Fraction(int n,int d)
            {
                nu=n;
                de=d;
            }
            Fraction operator +(Fraction obj)
            {
                Fraction temp;
                temp.de= de*obj.de;                // 5/6 + 4/3 = (5*3 +4*6 )/6*3
                temp.nu= (nu*obj.de)+(de*obj.nu);
                return temp;
            }
            Fraction operator -(Fraction ob)
            {
                Fraction t;
                t.de= de*ob.de;
                t.nu= (nu*ob.de)-(de*ob.nu);
                return t;
            }
            Fraction operator *(Fraction obj)
            {
                Fraction dummy;
                dummy.nu= nu*obj.nu;
                dummy.de= de*obj.de;
                return dummy;
            }
             void operator ==(Fraction obj)
            {
            float a,b;
            a=((float)nu)/de;
            b=((float)obj.nu)/obj.de;
            if(a>b)
                cout<<"1st Fraction is bigger."<<endl;
            else if(a==b)
                cout<<"Both Fractions  are EQUAL."<<endl;
            else
                cout<<"2nd Fraction is bigger."<<endl;
            }
            void display()
            {
            for( int i=de/2;i>1;i--)              //because a number does not have factors after its half value
            {
                if((nu%i==0)&&(de%i==0))
                {
                    nu=nu/i;
                    de=de/i;
                }
            }
            cout<<"Answer: ";
            if(de<nu)
            {
                int a=nu/de;
                int b=nu%de;                    // 7/3 = 2 and 1/3 Mixed fraction
                cout<<"Mixed Fraction : "<<a<<"("<<b<<"/"<<de<<")"<<endl;
            }
            else if(nu==de)
                cout<<"1"<<endl;
            else if(nu==0)
                cout<<"0"<<endl;
            else if(de==0)
                cout<<"Infinity"<<endl;
            else
                cout<<nu<<"/"<<de<<endl;
            }
};
int main()
{
    int n1,n2,d1,d2;
    cout<<"Enter numerator and denominator of the fraction: ";
    cin>>n1>>d1;
    cout<<"Enter 2nd fraction: ";
    cin>>n2>>d2;
    Fraction A(n1,d1);
    Fraction B(n2,d2);
    Fraction C=A+B;
    cout<<"Addition: ";
    C.display();
    Fraction D=A-B;
    cout<<"Subtraction: ";
    D.display();
    Fraction E=A*B;
    cout<<"Multiplication: ";
    E.display();
    A==B;
    return 0;
    
}