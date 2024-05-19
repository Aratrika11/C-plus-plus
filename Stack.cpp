#include<iostream>
using namespace std;

class Stack 
{
    int ar[5],top;
    public:
            Stack()
            {
                top=-1;
            }
            void push()
            {
                int b;
                top++;
                int q=isFull();
                if(q==1)
                cout<<"Overflow\n"<<endl;
                else
                {
                    cout<<"Enter number to be pushed: ";
                    cin>>b;
                    ar[top]=b;
                }
            }
            void pop()
            {
                int p=isEmpty();
                if(p==1)
                cout<<"Underflow"<<endl;
                else
                {
                    cout<<"ELement removed"<<endl;
                    top--;
                }
                
            }
            int isEmpty()
            {
                if(top==-1)
                return 1;
                else
                return 0;
            }
            int isFull()
            {
                if(top>=5)
                return 1;
                else
                return 0;
            }
            void display()
            {
                 cout<<"\nStack : ";
                for(int i=0;(i<=top)&&(i<5);i++)
                    cout<<ar[i]<<" ";
                cout<<"\n";
            }
};
int main()
{
    Stack A;
    int a;
    while(1)
    {
        cout<<"\nEnter 1 for Push & 2 for POP & 3 for Display  and any number to exit \n"<<"\nEnter your choice : ";
        cin>>a;
        switch(a)
        {
            case 1:
                /*cout<<"Enter a number : ";
                cin>>b;*/
                A.push();
                break;
            case 2:
                A.pop();
                break;
            case 3:
                A.display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
    
    
}