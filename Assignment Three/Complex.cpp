#include<iostream>
using namespace std;

class Complex
{
    int real,img;
    public:
            Complex()
            {
                real=0;
                img=0;
            }
            Complex(int r,int i)
            {
                real=r;
                img=i;
            }
            int operator ==(Complex b)
            {
                if(real==b.real && img==b.img)
                {
                    return 1;
                }
                else 
                    return 0;
            }
            void display()
            {
                cout<<real;
	            if(img>0)
	                cout<<"+"<<img<<"i"<<endl;
	            else
	                cout<<img<<"i"<<endl;
            }
};
    
int main()
{
    int r1,r2,img1,img2;
    cout<<"Enter the 1st  Complex Number"<<endl;
    cout<<"Enter real part: ";
    cin>>r1;
    cout<<"Enter imaginary part: ";
    cin>>img1;
    Complex A(r1,img1);

    cout<<"Enter the 2nd  Complex Number\n"<<endl;
    cout<<"Enter real part: ";
    cin>>r2;
    cout<<"Enter imaginary part: ";
    cin>>img2;
    Complex B(r2,img2);

   
    if(A==B)
    {
        cout<<"Both the complex numbers are same\n";
        A.display();
        B.display();
    }
    else
    {
    cout<<"The complex numbers are not same\n";
    A.display();
    B.display();
    }
    return 0;
}