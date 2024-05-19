#include<iostream>
#include<string>
using namespace std;

class Student 
{
    int roll,m[3],tot;
    string name;
    public:
        Student()
        {
            roll=0;
            tot=0;
            name="";
        }
        void input()
        {
            cout<<"\nEnter the name : ";
            cin>>name;
            //getline(cin,name);
            cout<<"Enter the roll number : ";
            cin>>roll;
            cout<<"Enter marks of the 3 subjects :\n";
            for(int i=0;i<3;i++)
            {
                cin>>m[i];
                tot=tot+m[i];;
            }
        }
        void display()
        {
            cout<<"\nName : "<<name<<"\nRoll Number : "<<roll;
            cout<<"\nMarks: ";
            for(int i=0;i<3;i++)
                cout<<m[i]<<",";
            cout<<"\nTotal marks : "<<tot<<endl;
        }
        void modify()
        {
            int x,v;
            cout<<"Enter which marks to be modified m1/m2/m3\n";
            cin>>x;
            cout<<"Enter  the  modified marks :\n";
            cin>>v;
            m[x-1]=v;
            tot=m[0]+m[1]+m[2];
        }
};

int main()
{
    int n,i,x;
    cout<<"Enter the number of students : ";
    cin>>n;
    Student A[n];

    for(i=0;i<n;i++)
    {
        cout<<"\nStudent "<<i+1<<"\n";
        A[i].input();
    }

    cout<<"\nDISPLAY : ";
    for(i=0;i<n;i++)
    {
        cout<<"Student "<<i+1<<"\n";
        A[i].display();
        cout<<endl;
    }

    int m;
    cout<<"\nEnter the student number for modification : ";
    cin>>m;
    A[m-1].modify();

    cout<<"\nAfter modification :\nStudent "<<m<<"\n";
    A[m-1].display();

}