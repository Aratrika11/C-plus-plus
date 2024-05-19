/*HIERARCHIAL INHERITANCE*/

#include<iostream>  
#include<math.h> 
#include<string>
using namespace std;

class Account
{
	protected:
		char name[100];
		int acctNO,type;
	public:
		Account()
		{
			name[0]='\0';
			acctNO=0;
			type=0;
		}
		Account(char *n,int acc)
		{
			int i;
			for(i=0;n[i]!='\0';i++)
				name[i]=n[i];
			acctNO=acc;
		}
		void input()
		{
			cout<<"Enter 1 for opening Savings Bank Acct. OR Enter 2 for opening Current Bank Acct.\nEnter your choice : ";
			cin>>type;
		}
		int get()
		{
			return type;
		}
		void display()
		{
			cout<<"\nName : "<<name<<"\nAcct. No. : "<<acctNO;
		}	
};

class Savings:public Account
{
	float minbal,penbal,bal;
	public:
		Savings(char *s,int an,float b):Account(s,an)
		{
			minbal=2000;
			penbal=100;
			bal=b;
		}
		void interest(float r,int t)
		{
			float intr,ci,d;
			intr=(bal*r*t)/100;     //SIMPLE INTEREST
			d=1+r/100;
			ci=bal*(pow(d,t))-bal;   //COMPOUND INTEREST
			bal=bal+ci;
			cout<<"Simple Interest: "<<intr<<"\nCompound Interest: "<<ci<<"\nResultant Amount: "<<bal<<endl;
			cout<<"_______________________________________________\n";
		}
		void deposit(float dep)
		{
			bal=bal+dep;
		}
		void withdraw(float w)
		{
			float c=bal-w;
			if(c<minbal)
			{
				bal=c-penbal;
				cout<<"Your remaining balance after withdrawal was below minimum deposit amount hence a penalty of Rs.200 was imposed"<<endl;
				cout<<"Account Balance: "<<bal<<endl;
				cout<<"_______________________________________________\n";
			}
			else
			{
				bal=bal-w;
				cout<<"Account Balance: "<<bal<<endl;
				cout<<"______________________________________\n";
			}
		}
		void display()
		{
			cout<<"\nCurrent Balance in your account : "<<bal;
		}
		
};

class Current:public Account
{
	float minbal,penbal,bal;
	public:
		
		Current(char *s,int an,float b):Account(s,an)
		{
			minbal=10000;
			penbal=500;
			bal=b;
		}
		void interest(float r,int t)
		{
			float intr;
			intr=(bal*r*t)/100;
			bal=bal+intr;
			cout<<"Interest: "<<intr<<"\nResultant Amount: "<<bal<<endl;
			cout<<"_______________________________________________\n";
		}
		void deposit(float dep)
		{
			bal=bal+dep;
		}
		void withdraw(float w)
		{
			if((bal-w)<minbal)
			{
				bal=bal-w-penbal;
				cout<<"Your remaining balance after withdrawal was below minimum deposit amount hence a penalty of Rs.500 was imposed"<<endl;
				cout<<"Account Balance: "<<bal<<endl;
				cout<<"_______________________________________________\n";
			}
			else
			{
				bal=bal-w;
				cout<<"Account Balance: "<<bal<<endl;
				cout<<"______________________________________\n";
			}
		}
		void display()
		{
			cout<<"\nCuurent Balance in your account : "<<bal;
		}
};

int main()
{
	Account obj;
	char n[100];
	float b;
	int accno;
	cout<<"____________BANK_____________\n";
	cout<<"Enter your name : ";
	cin.get(n,100);
	obj.input();
	int x=obj.get();
	int v,t;
	float d;
	Account *p;

	if(x==1)
	{
			cout<<"___________SAVINGS ACCOUNT__________"<<endl;
			cout<<"The minimum balance of Savings account is rupees 2000 and if the balance level falls below rupees 2000, then rupees 100 will be penalised";
			cout<<"\nEnter your 1st deposit : ";
			cin>>b;
			cout<<"Enter your account number: ";
			cin>>accno;
			Savings obj1(n,accno,b);
			p=&obj1;
			p->display();
			obj1.display();
			cout<<"\nYour account has been created.\n";
	

			cout<<"___________SAVINGS ACCOUNT__________"<<endl;
		    cout<<"Enter 1 to deposit , Enter 2 to withraw amount , Enter 3 to calculate and deposit interest \n";
			cin>>v;
			switch(v)
			{
				case 1: cout<<"Enter amount to be deposited: ";
						cin>>d;
						obj1.deposit(d);
						break;
				case 2: cout<<"Enter amount for withdrawal: ";
						cin>>d;
						obj1.withdraw(d);
						break;
				case 3: cout<<"Enter time period for interest: ";
						cin>>t;
						obj1.interest(10,t);
						break;
				default: cout<<"Invalid";
			}
			p->display();
			obj1.display();
			
	}
	else if(x==2)
	{
			cout<<"__________CURRENT ACCOUNT__________"<<endl;
			cout<<"The minimum balance of Current account is rupees 10000 and if the balance level falls below rupees 10000, then rupees 500 will be penalised";
			cout<<"\nEnter your 1st deposit : ";
			cin>>b;
			cout<<"Enter your account number: ";
			cin>>accno;
			Current obj2(n,accno,b);
			obj2.display();
			p=&obj2;
			p->display();
			obj2.display();
			cout<<"\nYour account has been created.\n";
	

			cout<<"___________CURRENT ACCOUNT__________"<<endl;
		    cout<<"Enter 1 to deposit , Enter 2 to withraw amount , Enter 3 to calculate and deposit interest \n";
			cin>>v;
			switch(v)
			{
				case 1: cout<<"Enter amount to be deposited: ";
						cin>>d;
						obj2.deposit(d);
						break;
				case 2: cout<<"Enter amount for withdrawal: ";
						cin>>d;
						obj2.withdraw(d);
						break;
				case 3: cout<<"Enter time period for interest: ";
						cin>>t;
						obj2.interest(12.5,t);
						break;
				default: cout<<"Invalid";
			}
			p->display();
			obj2.display();
	}		
	
	
	return 0;
}