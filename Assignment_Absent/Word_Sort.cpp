//WAP to arrange the words (user input) in dictionary manner....

#include<iostream>
#include<cstring>
using namespace std;

class Word
{
    char *str;
    int l;
    public:
        Word()
        {}
        Word(string s)
        {
            l=s.size();
            str=new char[l];
            for(int i=0;i<l;i++)
                str[i]=s[i];
        }
        Word(int length)
        {
            l=length;
            str=new char[l];
        }
        friend void sort(Word A[],int n);

        Word& operator = (Word const &obj)
        {
            l=obj.l;
            str=new char[l];
            for(int i=0;i<l;i++)
                str[i]=obj.str[i];
            return *this;
        }
        int get()
        {
            return l;
        }
        void display()
        {
            for(int i=0;i<l;i++)
                cout<<str[i];
        }
};

void sort(Word *A,int n)
{
    int i,j;
    Word B;
    for(i=0;i<n;i++)
    {
        
        for(j=i+1;j<n;j++)
        {
            int k,x=0;
            if(A[i].get()>A[j].get())
                k=A[j].get();
            else
                k=A[i].get();
            while(x<k)
            {
                if(A[i].str[x]>A[j].str[x])
                {
                    B=A[i];
                    A[i]=A[j];
                    A[j]=B;
                    break;
                }
                else if(A[i].str[x]==A[j].str[x])
                    x++;
                else
                    break;
            }
        }
    }
}

int main()
{
    int n,i;
    string s;
    cout<<"Enter the number of words you want to enter : ";
    cin>>n;
    Word *A=new Word[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter WORD "<<i+1<<" : ";
        cin>>s;
        A[i]=Word(s);
    }
    sort(A,n);
    cout<<"\nAfter sorting :\n-------------------\n";
    for(i=0;i<n;i++)
    {
        cout<<"Word "<<i+1<<" : ";
        A[i].display();
        cout<<endl;
    }
    return 0;
}