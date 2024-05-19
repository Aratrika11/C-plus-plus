/*Class Student with members Name, age , enrollment ID. Class Engineering with members CGPA. Then create two objects 
of Engineering and compare both students display 1st or 2nd*/

#include<iostream>
#include<cstring>
using namespace std;

class Student
{
	public:
		int age,enID;
		char name[50];
		Student()
		{
			age=0;
			enID=0;
			name[0]='\0';
		}
		Student(int x,int y,char *p)
		{
			age=x;
			enID=y;
			for(int i=0;p[i]!='\0';i++)
				name[i]=p[i];
		}
		void display()
		{
			cout<<"DETAILS \n";
			cout<<"NAME: "<<name<<endl;
			cout<<"AGE: "<<age<<endl;
			cout<<"ENROLLID: "<<enID<<endl;
		}
};
class Engg:public Student
{
	public:
		int cgpa;
		Engg()
		{
			cgpa=0;
		}
		Engg(int cg,int a,int en, char *ar):Student(a,en,ar)
		{
			cgpa=cg;
		}
		friend Engg operator >(Engg ob1,Engg ob2);
		void display()
		{
			cout<<"CGPA: "<<cgpa<<endl;
		}
};

Engg operator >(Engg ob1, Engg ob2)
{
	if(ob1.cgpa>ob2.cgpa)
		return ob1;
	else 
		return ob2;
}

int main()
{
	char ar[50],ar2[50],a;
	int a1,a2,en1,en2,cg1,cg2;
	cout<<"ENTER for STUDENT 1\n\n";
	cout<<"Enter Name: ";
	cin.get(ar,50);
	cout<<"Enter age and enID: ";
	cin>>a1>>en1;
	cout<<"Enter cgpa of Student: ";
	cin>>cg1;
	Engg obj1(cg1,a1,en1,ar);
	
	cout<<"\nENTER for STUDENT 2\n\n";
	cout<<"Enter Name: ";
	cin>>a;
	cin.get(ar2,50);
	cout<<"Enter age and enID: ";
	cin>>a2>>en2;
	cout<<"Enter cgpa of Student: ";
	cin>>cg2;

	Engg obj(cg2,a2,en2,ar2);
	
	Engg C=(obj1>obj);
	Student *p=&C;
	p->display();
	C.display();
	return 0;
}