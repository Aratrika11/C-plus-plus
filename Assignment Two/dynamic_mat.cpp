#include<iostream>
using namespace std;

class Array 
{
    int s=0,m,n,**ar;
    public: Array(int m1,int n1)
            {
                m=m1;
                n=n1;
                ar=new int *[m];
                for(int i=0;i<n;i++)
                {
                    ar[i]=new int[n];
                }
            }
            void input()
            {
                cout<<"Enter array elements\n";
                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cin>>ar[i][j];
                    }
                }
            }
            void sum()
            {
                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        s=s+ar[i][j];
                    }
                }
                cout<<"Sum "<<s;
            }
};
int main()
{
    Array obj(2,2);
    obj.input();
    obj.sum();
    return 0;
}