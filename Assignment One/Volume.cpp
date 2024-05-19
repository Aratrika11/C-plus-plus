#include<iostream>
using namespace std;
class Volumme
{
    float vol;
    public:
            Volumme()
            {
                vol=0.0;
            }
            void volume(int l)
            {
                vol=l*l*l;
                cout<<"Volume of Cube of side "<<l<<"= "<<vol<<endl;
                cout<<"_______________________________\n";
            }
            void volume(int l,int b,int h)
            {
                vol=l*b*h;
                cout<<"Volume of Rectangular Box= "<<vol<<endl;
                cout<<"_______________________________\n";
            }
            void volume(int r,int h)
            {
                vol=3.14*r*r*h;
                cout<<"Volume of Cylinder= "<<vol<<endl;
                cout<<"_______________________________\n";
            }
};
int main()
{
    Volumme obj;
    int s,l,b,h,r,dh,ch;
    int a=1;
    while(a==1)
    {
        cout<<"1. Enter 1 for Cube \n2. Enter 2 for Rectangular Box \n3.Enter 3 for Cone \nEnter your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
                    cout<<"Enter side of cube: ";
                    cin>>s;
                    obj.volume(s);
                    break;
            case 2:
                    cout<<"Enter length breadth and height of box\n";
                    cin>>l>>b>>h;
                    obj.volume(l,b,h);
                    break;
            case 3:
                    cout<<"Enter radius and height of cylinder\n";
                    cin>>r>>dh;
                    obj.volume(r,dh);
                    break;
            default:cout<<"INVALID CHOICE";
        }
        cout<<"a.Enter 1 to continue \nb. Enter 0 to exit\n:";
        cin>>a;
    }
    return 0;
}