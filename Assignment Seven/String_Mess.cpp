#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class String
{
	public:
			char *s;
			int length;
			String()
			{
				length=100;
				s=new char[length];
			}
			String(int x)
			{
				string st = to_string(x);
				st=st+" ";
				length= st.length();
				s= new char[length];
				for(int i=0;i<length;i++)
					*(s+i)=st[i];
				//for(int i=0;i<length;i++)
					//cout<<*(s+i);
			}
			String(string str)
			{
				str=str+" ";
				length=str.length();
				s=new char[length];
				for(int i=0;i<length;i++)
					*(s+i)=str[i];
			}
			/*String(String const &obj)
			{
				s=new char[obj.length];
				length=obj.length;
				cout<<"Calling Copy Constructor\n";
				for(int i=0;i<length;i++)
					*(s+i)=*(obj.s+i);
			}*/
			String operator +(String obj)
			{
				String temp;
				int j=length;
				for(int i=0;i<length;i++)
					*(temp.s+i)=*(s+i);
				for(int i=0;i<obj.length;i++)
				{
					*(temp.s+j)=*(obj.s+i);
					j++;
				}
				return temp;
			}
			void operator ==(String obj)
			{
				if(strcmp(s,obj.s)==0)
					cout<<"Both String are Equal\n";
				else
					cout<<"Strings are not equal\n";
			}
			void operator >(String obj)
			{
				if(strlen(s)>strlen(obj.s))
					cout<<"String 1 is greater\n";
				else
					cout<<"B is greater\n";
				
			}
			void operator <(String obj)
			{
				if(strlen(s)<strlen(obj.s))
					cout<<"String 2 is greater\n";
				else
					cout<<"A is greater\n";
				
			}

			friend void compare(char &str, string s2);
			friend void convert(string s,char &str);

			void display()
			{
				for(int i=0;i<length;i++)
					cout<<*(s+i);
				cout<<"\n";
				//cout<<s<<endl;
			}
			/*~String()
			{
				cout<<"Destructed";
				delete s;
			}*/
};
void compare(String obj, string s2)
{
	int i = s2.compare(obj.s);  
      
    if ( i < 0)  
    {  
        cout << s2 << " is smaller than " << " string object" << endl;  
    }  
      
    else if ( i > 0)  
    {  
        cout << s2 << " is greater than "  << " string.object " << endl;  
    }  
    else 
    {  
        cout << " Both strings are equal.";  
    }    
}

void convert(string s)
{
	char *str;
    int n = s.length();
    str= new char[n + 1];
    strcpy(str, s.c_str());
 
    for (int i = 0; i < n; i++)
        cout <<*(str+i);
}

int main()
{
	int x;char a;
	string str;
	cout<<"Enter numeric part: ";
	cin>>x;
	String A(x);
	A.display();
	cout<<"\n";
	cout<<"Enter string part: ";
	cin>>str;
	//getline(cin,str);
	String B(str);
	B.display();
	cout<<"\n";
	String C=A+B;
	C.display();
	cout<<"_______________________________\n";
	cout<<"OPERATOR OVERLOADING\n";
	String obj("APPLE");
	obj.display();
	String ob("BANANA");
	ob.display();
	obj==ob;
	cout<<"_______________________________\n";
	obj>ob;
	cout<<"_______________________________\n";
	obj<ob;
	cout<<"_______________________________\n";
	cout<<"Comparing String with String Object\n";
	compare(B,"Aratrika");
	cout<<"_______________________________\n";
	int l;
	/*cout<<"Enter length of the character array";
	cin>>l;
	char *ch=new char[l];
	cout<<"Enter the character array";
	cin>>ch;*/
	cout<<"CONVERSION\n";
	convert("Aratrika");

	return 0;
}