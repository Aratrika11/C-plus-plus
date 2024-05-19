#include<iostream>
using namespace std;

class Matrix
{
    int *p,r1,c1;
    public:
            Matrix(int r,int c)
            {
                r1=r;
                c1=c;
                p=new int[r*c];
                //q=new int[r2*c2];
            }
            void input()
            {
                int i,j;
                cout<<"Enter the elements";
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c1;j++)
                    {
                        cin>>*(p+(i*c1)+j);
                    }
                }
                
            }
            Matrix operator +(Matrix ob)
            {
                Matrix temp(r1,c1);
                    for(int i=0;i<r1;i++)
                    {
                        for(int j=0;j<c1;j++)
                            *(temp.p+(i*ob.c1)+j)=*(p+(i*c1)+j)+*(ob.p+(i*ob.c1)+j);
                    }
                return temp;
            }
            Matrix operator *(Matrix obj)
            {
                Matrix temp(r1,obj.c1);
                for(int i=0;i<r1;i++)
                {
                    for(int j=0;j<obj.c1;j++)
                    {
                        for(int k=0;k<c1;k++)
                        {
                            *(temp.p+(i*obj.c1)+j) += *(p+(i*c1)+k)*(*(obj.p+(k*obj.c1)+j));
                        }
                    }
                }
                return temp;
            }
            Matrix transpose()
            {
                Matrix t(c1,r1);
                for(int i=0;i<r1;i++)    //i runs in row of original
                {
                    for(int j=0;j<c1;j++)     //j runs in coloumn of original 
                    {
                        *(t.p+(j*t.c1)+i)=*(p+(i*c1)+j);     //transpose row and coloumn interchange
                    }
                }
                return t;
            }
            void display()
            {
                int i,j;
                cout<<"MATRIX\n";
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c1;j++)
                    {
                        cout<<*(p+(i*c1)+j)<<" ";
                    }
                    cout<<endl;
                }
                
            }
};

int main()
{
    int r,c,r2,c2;
    cout<<"Enter value of row and coloumn ";
    cin>>r>>c;
    
    Matrix A(r,c);
    A.input();
    A.display();
    
    cout<<"Enter value of row and coloumn ";
    cin>>r2>>c2;
    Matrix B(r2,c2);
    B.input();
    B.display();

    int a;
    cout<<"\n1. Enter 1 for Addition \n2. Enter 2 for Multiplication \n3. Enter 3 for Transpose";
    cout<<"\nEnter choice: ";
    cin>>a;
    if(a==1)
    {

       if(r==r2 && c==c2)
        {
            Matrix C=A+B;
            cout<<"ADDITION"<<endl;
            C.display();
        }
        else
            cout<<"Addition not possible"<<endl;
    }
    else if(a==2)
    {
        if(c==r2)
        {
            Matrix C=A*B;
            cout<<"MULTIPLICATION"<<endl;
            C.display();
        }
        else
            cout<<"Multiplication not possible"<<endl;
    }
    else if(a==3)
    {
        Matrix D=A.transpose();
        cout<<"TRANSPOSE"<<" ";
        D.display();
    }
    else
        cout<<"INVALID";
    return 0;
}