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
            Complex operator +(Complex obj)
            {
                Complex temp;
                temp.real=real+obj.real;
                temp.img=img+obj.img;
                return temp;
            }
            void display()
            {
                cout<<real<<"+"<<img<<"i"<<endl;
            }
};
int main()
{
    Complex A(5,6);
    Complex B(6,7);
    Complex C=A+B;
    C.display();
}