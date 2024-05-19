#include<iostream>
using namespace std;

class Array
{
    private: int *ptr,size;
    public:
            Array()
            {
                cout<<"Enter array size";
                cin>>size;
                ptr=new int[size];       //dynamically allocating memory
            }
            void input()
            {
                int i;
                cout<<"Enter the elements"<<endl;
                for(i=0;i<size;i++)
                    cin>>*(ptr+i);
            }
            Array(Array &obj)
            {
                cout<<"Copy constructor called"<<endl;
                size = obj.size;
                ptr=new int[obj.size];
                for(int i=0;i<obj.size;i++)
                {
                    *(ptr+i)=*(obj.ptr+i);
                }
                for(int i=0;i<obj.size;i++)
                {
                    cout<<*(ptr+i);
                }
            }
            void sort()
            {
                int i,j,temp;
                for(i=0;i<size;i++)             
                {
                    for(j=i;j<size;j++)
                    {
                        if(*(ptr+i)>*(ptr+j))
                        {
                            temp=*(ptr+j);
                            *(ptr+j)=*(ptr+i);
                            *(ptr+i)=temp;
                        }
                    }
                }

            }
            void display()
            {
                cout<<"New array [ ";
                for(int i=0;i<size;i++)
                    cout<<*(ptr+i)<<" ";
                cout<<" ]";
            }
};
int main()
{
    Array S;
    S.input();

    Array S1=S;         //Shallow copy

    S.sort();
    cout<<"Sorted"<<endl;
    S.display();
    S1.display();       
    return 0;

}