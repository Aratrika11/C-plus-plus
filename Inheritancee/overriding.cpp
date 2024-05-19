/*Using of virtual function to prevent the overruling of overriding and understanding virtual table
and virtual pointer*/

#include<iostream>
using namespace std;						//bit stuffing -> Multiple of 8 

class A
{
	public:
		int x,y;
		A()
		{
			x=0;
			y=0;
		}
		virtual void print()                         //size = 4+4 = 8  (int + int)
		{
			cout<<x<<y;
		}                           			// 8+8=16....Final size = 16 (8 for pointer size)
		void input()
		{
			cout<<"Enter value of x and y : ";
			cin>>x>>y;
		}
};

class B: public A
{
	public:
		int a,b,c;
		B()
		{
			a=5;					//inherited size = 16
		}						//this class has size : 4+4+4 = 12
		void print()					//Total size = 16+12 = 28 ....but 28 is not a multiple of 8. So 4 butes are stuffed 
		{						// Final size is 32.
			cout<<endl<<endl<<a;
		}
		virtual void display()
		{
			cout<<"Vdisplay : "<<a;
		}
};

class C: public B
{
	public:
		double b;
		C()
		{						//inherited size = 32
			b=523.115;				//this class has size 8 (for double)
		}						//total size = 32+8 = 40.......it is a multiple of 8...So final size is 40
		void display()
		{
			cout<<endl<<endl<<b;		
		}
};

int main()
{
	A obj1;
	B obj2;
	C obj3;
	int s=sizeof(obj1);
	int u=sizeof(obj2);
	int v=sizeof(obj3);
	cout<<"size : ";
	cout<<endl<<s<<endl<<u<<endl<<v;
	return 0;
}