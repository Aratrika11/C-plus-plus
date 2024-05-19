#include<iostream>
#include<math.h>
using namespace std;


class Cone 
{
   float r,h,ar,vol;
   public:
      Cone()
      {
         r=0.0;
         h=0.0;
      }
      Cone(float r,float h)
      {
         this->r=r;
         this->h=h;
      }
      Cone (Cone &obj)
      {
         r=obj.r;
         h=obj.h;
      }

      void input()
      {
         cout<<"CONE :\nEnter the radius : ";
         cin>>r;
         cout<<"Enter the height : ";
         cin>>h;
      }

      void volume()
      {
         vol=(3.14*r*r*h)/3;
         
      }

      void area()
      {
        ar=3.14*r*(r+sqrt((h*h)+(r*r)));
      }

      void display()
      {
         cout<<"Area = "<<ar<<"\nVolume = "<<vol;
      }

};

int main()
{
   Cone A;
   A.input();
   A.area();
   A.volume();
   A.display();

   float r,h;
   cout<<"\n\nEnter the radius and height of the 2nd cone : ";
   cin>>r>>h;
   Cone B(r,h);
   B.area();
   B.volume();
   B.display();

   Cone C=A;
   cout<<"\n\nCopy of 1st Cone :\n";
   C.area();
   C.volume();
   C.display();

   return 0;
}