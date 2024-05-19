/*WAP to overload the insertion and extraction operator and use operator overloading to 
add Two Complex numbers*/

#include<iostream>
using namespace std;

class Complex
{
	int real,img;
	public: Complex()
		{
		   real=0;
		   img=0;
		}
		friend istream & operator >>(istream &in,Complex &obj);
		friend ostream & operator <<(ostream &out,Complex &obj);
		Complex operator +(Complex obj)
		{
		    Complex temp;
		    temp.real=real+obj.real;
		    temp.img=img+obj.img;
		    return temp;
		}

};
istream & operator >>(istream &in,Complex &obj)
{
	cout<<"Enter real part: ";
	in>>obj.real;
	cout<<"Enter imaginary part: ";
	in>>obj.img;
	return in;
}
ostream & operator <<(ostream &out,Complex &obj)
{
	out<<obj.real;
	if(obj.img>0)
	out<<"+"<<obj.img<<"i"<<endl;
	else
	out<<obj.img<<"i"<<endl;
	return out;
}
int main()
{
	Complex A,B;
	cout<<"Enter the 1st  Complex Number"<<endl;
	cin>>A;
	cout<<"1st: "<<A<<endl;
	cout<<"Enter the 2nd Complex Number "<<endl;
	cin>>B;
	cout<<"2nd: "<<B<<endl;
	
	cout<<"AFTER ADDITION: "<<endl;
	Complex C=A+B;
	cout<<C;
	return 0;
}