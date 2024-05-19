
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Staff
{
	public:
		char name[50];
		int code;
		float sal;
		Staff()
		{
			name[0]='\0';
			code=0;
			sal=0.0;
		}
		Staff(char *s,int c)
		{
			for(int i=0;s[i]!='\0';i++)
				name[i]=s[i];
			code=c;
		}
		virtual void salary()=0;
};
class Officer: public Staff
{
	public:
		char g;
		Officer(char *s,int code,char gr):Staff(s,code)
		{
			g=gr;
		}
		void salary()
		{
			if(g=='A')
				sal=80000;
			else if(g=='B')
				sal=60000;
			else if(g=='C')
				sal=40000;
			else if(g=='D')
				sal=30000;
			else
				cout<<"\nNo such grade exists\n";
		}
		void display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"Staff Code: "<<code<<endl;
			cout<<"Salary: "<<sal<<endl;
		}
};
class Teacher: public Staff
{
	public:
		string sub;
		Teacher(string subject,char *s,int code):Staff(s,code)
		{
			sub=subject;
		} 
		void salary()
		{
			float yrs;
			cout<<"Enter teaching years: ";
			cin>>yrs;
			if(yrs<=5)
				sal=20000;
			else if(yrs>5 && yrs<=10)
				sal=30000;
			else if(yrs>=11 && yrs<=15)
				sal=40000;
			else if(yrs>15)
				sal=55000;
		}
		void display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"Staff Code: "<<code<<endl;
			cout<<"Salary: "<<sal<<endl;
		}
};
class Typist: public Staff
{
	public:
		float sp;
		Typist(char *s,int code,float sd):Staff(s,code)
		{
			sp=sd;
		}
		void display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"Staff Code: "<<code<<endl;
		}	
};
class CTypist: public Typist
{
	public:
		int dw;
		CTypist(char *s,int code,int dwg,float speed):Typist(s,code,speed)
		{
			dw=dwg;
		}
		void salary()
		{
			if(sp<40)
				sal=dw*12;
			else if(sp>40 && sp<=100)
				sal=dw*12+10000;
			else if(sp>100)
				sal=dw*12+25000;
		}
		void display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"Staff Code: "<<code<<endl;
			cout<<"Salary: "<<sal<<endl;
		}
};
class RTypist: public Typist
{
	public:
		int renum;
		RTypist(char *s,int code,int re,float speed):Typist(s,code,speed)
		{
			renum=re;
		}
		void salary()
		{
			if(sp<40)
				sal=renum;
			else if(sp>40 && sp<=100)
				sal=renum+15000;
			else if(sp>100)
				sal=renum+25000;
		}
		void display()
		{
			cout<<"NAME: "<<name<<endl;
			cout<<"Staff Code: "<<code<<endl;
			cout<<"Salary: "<<sal<<endl;
		}
};

int main()
{
	char name[50],sub[10],gd;
	int ch,code,dw,renum;
	float speed;
	string str;

	cout<<"\nEnter Name of Staff: ";
	cin.get(name,50);
	cout<<"Enter Staff code: ";
	cin>>code;
	cout<<"Enter 1 for Officer _____Enter 2 for Teacher ____Enter 3 for Casual Typist ____Enter 4 for Regular Typist\nEnter choice: ";
	cin>>ch;
	if(ch==1)
	{
		cout<<"\nEnter Grade of OFFICER: ";
		cin>>gd;
		Officer A(name,code,gd);
		A.salary();
		A.display();
	}
	else if(ch==2)
	{
		cout<<"\nEnter Subject of TEACHER: ";
		cin.get(sub,10);
		Teacher B(sub,name,code);
		B.salary();
		B.display();
	}
	else if(ch==3)
	{
		cout<<"\nEnter Spped of CASUAL TYPIST: ";
		cin>>speed;
		cout<<"\nEnter Daily Wages: ";
		cin>>dw;
		CTypist D(name,code,dw,speed);
		D.salary();
		D.display();
	}
	else if(ch==4)
	{
		cout<<"\nEnter Spped of REGULAR TYPIST: ";
		cin>>speed;
		cout<<"\nEnter Renumeration: ";
		cin>>renum;
		RTypist E(name,code,dw,speed);
		E.salary();
		E.display();
	}
	else
		cout<<"Wrong Choice";
	return 0;

		
}