#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Shape
{
	public: int l,h;
		Shape()
		{
			l=0;
			h=0;
		}
		Shape(int x)
		{
			l=x;       //for cube
		}
		Shape(int x, int y)
		{
			l=x;          //for cone
			h=y;
		}
		virtual void area()=0;
		virtual void volume()=0;
};

class Cube:public Shape
{
	public: double ar,vol;
		Cube()
		{
		}
		Cube(int x):Shape(x)
		{
			ar=0.0;
			vol=0.0;
		}
		/*void input()
		{
			cout<<"Enter side of a cube: ";
			cin>>l;
			h=l;
		}*/
		void area()
		{
			ar=6*l*l;
		}
		void volume()
		{
			vol=pow(l,3);
		}
		void display()
		{
			cout<<"Area= "<<ar<<endl;
			cout<<"Volume= "<<vol<<endl;
		}
};

class Cone: public Shape
{
	public: float ar, vol;
		Cone()
		{
			l=0;
			h=0;
		}
		Cone(int r,int height):Shape(r,height)
		{
			ar=0;
			vol=0;
		}
		void area()
		{
			float a=(h*h)+(l*l);
			float s=sqrt(a);
			ar=(3.14*l)*(l+s);
		}
		void volume()
		{
			vol=(3.14*l*l*h)/3;
		}
		void display1()
		{
			cout<<"Area= "<<ar<<endl;
			cout<<"Volume= "<<vol<<endl;
		}
};

int main()
{
	int ch;
	cout<<"1.Enter 1 for Cubes \n2.Enter 2 for Cones \nEnter choice: ";
	cin>>ch;
	if(ch==1)
	{
		Cube *obj=new Cube[5];
		int x,s;
		cout<<"Enter number of cubes: ";
		cin>>x;
		for(int i=0;i<x;i++)
		{
			cout<<"Cube "<<i+1;
			cout<<"\nEnter length: ";
			cin>>s;
			obj[i]=Cube(s);  //it is calling the parameterized constructor using a already declared obj of that class ..... just like function calling
			obj[i].area();
			obj[i].volume();
			obj[i].display();
		}
	}
	else if(ch==2)
	{
		Cone *obj1=new Cone[10];
		int y,a,b;
		cout<<"Enter number of Cones";
		cin>>y;
		for(int i=0;i<y;i++)
		{
			cout<<"Cone "<<i+1;
			cout<<"\nEnter radius and height: ";
			cin>>a>>b;
			obj1[i]=Cone(a,b);
			obj1[i].area();
			obj1[i].volume();
			obj1[i].display1();
		}
	}
	else
		exit(0);
	
	return 0;
}