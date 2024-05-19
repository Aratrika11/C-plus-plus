/*1 WAP to overload a function Add as char* Add(char, char), char* Add(char, char*), char* Add(char*, char) 
    to perform concatenation according as the arguments.
    cout<< Add(‘x’ ,’y’);		            //	would print ‘xy’
    cout<< Add(‘a’, “ Country”);	            //	would print ‘a Country’
    cout<< Add( “How are “, ‘U’);	//	would print ‘How are U’*/


#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Concat
{
    char *st;
    int l;
    public:
            Concat()
            {
                l=0;
            }
            Concat(string s)
            {
                s=" "+s+" ";
                l=s.length();
                st= new char[l];
                for(int i=0;i<l;i++)
                    st[i]=s[i];
            }
            char *get()
            {
                return st;
            }
            char * Add(char a, char b)
            {
                char *c=new char[2];
                c[0]=a;
                c[1]=b;
                return c;
            }
            char * Add(char a, char *b)
            {
                char *c= new char[l+1];
                c[0]=a;
                int j=0;
                for(int i=1;i<=l;i++)
                {
                    c[i]=*(b+j);
                    j++;
                }
                return c;
            }
            char * Add(char *a,char b)
            {
                char *c= new char[l+1];
                for(int i=0;i<l;i++)
                    c[i]=*(a+i);
                c[l]=b;
                return c;
            }
};

int main()
{
   char a,b;
   cout<<"Enter two characters: ";
   cin>>a>>b;
   Concat A;
   char *c=new char[2];
   c=A.Add(a,b);
   cout<<"1st Concatenation: "<<c[0]<<c[1];

   char st;
   cout<<"\nEnter a character: ";
   cin>>st;
   string s,skip;
   cout<<"Enter a string: ";
   getline(cin,skip);
   getline(cin,s);
   int len;
   s=s+" ";
   len=s.length();
   Concat B(s);
   char *chr=B.get();
   char *ch=new char[len +1];
   ch=B.Add(st,chr);
   cout<<"2nd Concatenation: ";
   for(int i=0;i<len+1;i++)
        cout<<ch[i];
    Concat C("Aratrika");
    char *d=C.get();
    char *dd=new char[11];
    dd=C.Add(d,'d');
    for(int i=0;i<11;i++)
        cout<<dd[i];


   return 0;
}

