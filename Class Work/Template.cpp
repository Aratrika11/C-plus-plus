/*WAP to implement generic stack using generic class */

#include<iostream>
using namespace std;

template <class T> class Stack
{
	T arr[5];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push()
		{
			T a;
			top++;
			int q=isFull(top);
			if(q==1)
			{
				cout<<"\nStack Overflow\n";	
				top=4;
			}
			else
			{
				cout<<"Enter the number: ";
				cin>>a;
				cout<<"Entered\n";
				arr[top]=a;
			}
		}
		void pop()
		{
			int q=isEmpty(top);
			if(q==1)
			{
				cout<<"Stack Underflow\n";
			}
			else if(top>=5)
			{
				top=4;
				top--;
			}
			else
			{
				top--;
				cout<<"Deleted\n";
			}
		}
		int isEmpty(int t)
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		int isFull(int t)
		{
			if(top>=5)
				return 1;
			else 
				return 0;
		}
		void display()
		{
			cout<<"Stack\n";
			for(int i=0;i<=top;i++)
				cout<<arr[i]<<" ";
			cout<<"\n";
		}
};
int main()
{
	Stack <int>A;
	int ch,a=1;
	while(a==1)
	{		
		cout<<"1.Enter 1 for value insertion \n 2.Enter 2 for value Deletion \n 3.Enter 3 for displaying value\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				A.push();
				break;
			case 2:
				A.pop();
				break;
			case 3:A.display();
				break;
			default:cout<<"INVALID\n";
		}
		cout<<"1.Enter 1 to continue \n2.Enter 2 to exit\n";
		cout<<"Enter choice: ";
		cin>>a;
	}
	return 0;
}