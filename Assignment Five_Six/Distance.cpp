#include<iostream>
using namespace std;

class Metre;
class Distance
{
	int feet;
	float inch;
	public:
		Distance()
		{
			feet=0;
			inch=0;
		}
		Distance(float a)
		{
			inch=a;
		}
		Distance(int b)
		{
			feet=b;
		}
		Distance(float a,int b)
		{
			inch=a;
			feet=b;
		}
		Distance(Distance const &obj)
		{
			feet=obj.feet;
			inch=obj.inch;
		}
		Distance input()
		{
			Distance S;
			cin>>S;
			return S;
		}
		void display()
		{
			Distance S;
            S.feet=feet;
            S.inch=inch;
			cout<<"Distance in feet and inches = "<<S;
		}
		Distance operator + (Distance obj)
		{
			Distance temp;
			temp.feet=feet+obj.feet;
			temp.inch=inch+obj.inch;
			return temp;	
		}
		friend double operator * (double x ,Distance &obj);
		
		operator float()
		{
			float a=(feet*12)+inch;
			return a;
		}
		operator int()
		{
			if(inch>=12)
			{
				int a= inch/12;
				feet+=a;
			}
			return feet;
		}

        //CLASS TO CLASS
		operator Metre();
		
		friend int operator > (Metre &obj1,Distance &obj2);
		friend int operator < (Metre &obj1,Distance &obj2);
		friend int operator >= (Metre &obj1,Distance &obj2);
		friend int operator <= (Metre &obj1,Distance &obj2);
		friend int operator == (Metre &obj1,Distance &obj2);
		friend istream &operator >>(istream &in, Distance &obj);
		friend ostream &operator <<(ostream &out, Distance &obj);
};

class Metre
{
	int mt;
	float cm;
	public: 
		Metre()
		{
			mt=0.0;
			cm=0;
		}
		Metre(float c)
		{
			cm=c;
		}
		Metre(int m)
		{
			mt=m;
		}
		Metre(int m,float c)
		{
			mt=m;
			cm=c;
		}
		/*Metre(Metre const&obj)
		{
			this->mt=obj.mt;
			this->cm=obj.cm;
		}*/
		Metre input()
		{
			Metre S;	
			cin>>S;
			return S;
		}
		void display()
		{
			Metre T;
            T.mt=mt;
            T.cm=cm;
			cout<<"Distance in metre and centimetre = "<<T;		
		}
		
		friend int operator > (Metre &obj1,Distance &obj2);
		friend int operator < (Metre &obj1,Distance &obj2);
		friend int operator >= (Metre &obj1,Distance &obj2);
		friend int operator <= (Metre &obj1,Distance &obj2);
		friend int operator == (Metre &obj1,Distance &obj2);
		friend istream &operator >>(istream &in, Metre &obj);
		friend ostream &operator <<(ostream &out, Metre &obj);

		
};

Distance::operator Metre()          //CLASS TO CLASS  (type casting)
		{
			float a=(feet*12)+inch;
			float b=a*2.54;
			return Metre(b);
		}
double operator * (double x,Distance &obj)
{
    //CONVERT TO METRE    
	float a=(obj.feet*12) + obj.inch;
	double b=a*x;
	return b; 	
}

istream &operator >>(istream &in,Distance &obj)        //Overloading insertion
{
	cout<<"Enter distance in feet"<<endl;
	in>>obj.feet;
	cout<<"\nEnter distance in inches: "<<endl;
	in>>obj.inch;
	return in;
}
ostream &operator <<(ostream &out, Distance &obj)          //Overloading extraction
{
	if(obj.inch>=12)
	{
		int a= obj.inch/12;
		obj.feet+=a;
		obj.inch=obj.inch-(a*12);
	}
	out<<obj.feet<<" feet "<<obj.inch<<" inch.\n";
    return out;
}

int operator > (Metre &obj1,Distance &obj2)
{
	float a=obj1.mt*100+obj1.cm;                  //centi                a->Met
	float b=obj2.feet*12+obj2.inch;                     //inches		
	float c=b*2.54 ;                                                //inches to centi             c->Dist
	if(a>c)
		return 1;
	else
		return 0;
}

int operator < (Metre &obj1,Distance &obj2)
{
	float a=obj1.mt*100+obj1.cm;                  //centi                a->Met
	float b=obj2.feet*12+obj2.inch;                     //inches		
	float c=b*2.54 ;                                               //inches to centi             c->Dist
	if(a<c)
		return 1;
	else
		return 0;
}

int operator == (Metre &obj1,Distance &obj2)
{
	float a=obj1.mt*100+obj1.cm;                  //centi                a->Met
	float b=obj2.feet*12+obj2.inch;                     //inches		
	float c=b*2.54 ;                                               //inches to centi             c->Dist
	if(a==c)
		return 1;
	else 
		return 0;
}

int operator >= (Metre &obj1,Distance &obj2)
{
	float a=obj1.mt*100+obj1.cm;                  //centi                a->Met
	float b=obj2.feet*12+obj2.inch;                     //inches		
	float c=b*2.54 ;                                                //inches to centi             c->Dist
	if(a>=c)
		return 1;
	else 
		return 0;
}

int operator <= (Metre &obj1,Distance &obj2)
{
	float a=obj1.mt*100+obj1.cm;                  //centi                a->Met
	float b=obj2.feet*12+obj2.inch;                     //inches		
	float c=b*2.54 ;                                                //inches to centi             c->Dist
	if(a<=c)
		return 1;
	else 
		return 0;
}

istream &operator >>(istream &in, Metre &obj)
{
	cout<<"Enter the metre part : ";
	in>>obj.mt;
	cout<<"Enter the centimetre : ";
	in>>obj.cm;
	return in;
}

ostream &operator <<(ostream &out, Metre &obj)
{
	out<<obj.mt<<" m "<<obj.cm<<" cm.\n";
	return out;
}

int main()
{
	Distance A;
	cout<<"Distance 1 :\n-----------------";
	A=A.input();
	Distance B;
	cout<<"Distance 2 :\n-----------------";
	B=B.input();
	Distance C=A+B;
	cout<<"Total ";
	C.display();
	
	cout<<"\nTotal distance in metre : ";
	double a=0.0254*C;                                 //total distance converted to inches then to metre by multiplying 0.0254
	cout<<a<<" m\n";

	int x,feet;
	float inches;
	cout<<"\nEnter 1 to change Total Distance  to full feet OR enter 2 to change to full inches\nEnter your choice : ";
	cin>>x;
	switch(x)
	{
		case 1:
			feet=(int)C;
			cout<<"\nTotal Distance in feet (only integer part) : "<<feet<<" feet\n";
			break;
		case 2:
			inches=(float)C;
			cout<<"\nTotal Distance in inches : "<<inches<<" inches\n";
			break;
		default:
			cout<<"Invalid Choice";
	}  
	
	Metre D=C;
	cout<<"Total ";
	D.display();  

	Distance X;
	cout<<("\nNew Distance :");
	X=X.input();
	Metre Y;
	cout<<("\nNew Metre :\n");
	Y=Y.input();
	
	if(Y==X)
		cout<<("Both are equal.\n");
	else if(Y<X)
		cout<<("Distance is greater.\n");
	else if(Y>X)
		cout<<("Metre is greater.\n");

	X.display();
	
	return 0;
}