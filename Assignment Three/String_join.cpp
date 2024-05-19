#include<iostream>
#include<string>
using  namespace std;

class Concat
{
    string str;
    public:
            Concat()
            {
                str="";
            }
            Concat(string s)
            {
                str=s;
                //cout<<str<<endl;
            }
           Concat operator +(Concat obj)
           {
               Concat temp;
               str=str+" ";
              /* int l=str.length();
               int k=obj.str.length();*/
               temp.str=str.append(obj.str);
               return temp;
           }
           void display()
           {
               cout<<str;
           }
};
int main()
{
    string s1,s2;
    
    cout<<"Enter the first string: ";
    getline(cin,s1);
    cout<<"Enter second string: ";
    getline(cin,s2);

  Concat A(s1);
  Concat B(s2);
  Concat C=A+B;
  cout<<"_________________________________\n";
  cout<<"AFTER JOINING\n";
  C.display();
  return 0;
  
}