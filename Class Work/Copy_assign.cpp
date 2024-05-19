#include<iostream>
using namespace std;

class Dummy
{
    private:int *ptr, size;
    public:
            Dummy(int x)
            {
                size=x;
                ptr=new int[size];
                
            }
            void input()
            {
                int i;
                cout<<"Enter elements: ";
                for(i=0;i<size;i++)
                    cin>>*(ptr+i);
            }
             Dummy & operator=(Dummy &obj)
            {
                //size=obj.size;
                //ptr=new int[size];
                for(int i=0;i<size;i++)
                    *(ptr+i)=*(obj.ptr+i);
                return *this;
            }
            void sort()
            {
                int temp;
                for(int i=0;i<size-1;i++)
                {
                    for(int j=0;j<size-i-1;j++)
                    {
                        if(*(ptr+j)>*(ptr+j+1))
                        {
                            temp=*(ptr+j);
                            *(ptr+j)=*(ptr+j+1);
                            *(ptr+j+1)=temp;
                        }
                    }
                }
            }
            void display()
            {
                cout<<"Array"<<endl;
                for(int i=0;i<size;i++)
                    cout<<*(ptr+i)<<" ";
                cout<<endl;
            }
    
};
int main()
{
    int size;
    cout<<"Enter size";
    cin>>size;
    Dummy obj(size);
    
    obj.input();
    Dummy obj1(size);
    obj1=obj;
    obj.sort();
    cout<<"\nSORTED NEW ARRAY\n";
    obj.display();
    cout<<"\nUNSORTED OLD ARRAY\n";
    obj1.display();
    return 0;
}