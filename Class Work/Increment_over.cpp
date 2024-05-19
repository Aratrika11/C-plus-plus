//Increment operator overloading . Incrementing more than 1.
#include<iostream>
using namespace std;

class Complex
{
    int a;
    public:
            Complex()
            {
                a=0;
            }
            Complex(int x)
            {
                a=x;
            }
            void operator ++(int)    //not returning any value so void 
            {
                a=a+5; /*working on itself hence nowhere else to store or return anything and any 
                changes on itself gets reflected.*/
            }
            void display()
            {
                cout<<a<<"\n";
            }
};
int main()
{
    Complex A(2);
    A++; //write int in the overloaded function
    //++A void parameter list of overloaded function
    A.display();
}
