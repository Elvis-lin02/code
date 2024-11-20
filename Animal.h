#include<iostream>
using namespace std;
class Animal
{
private:
   string name;
   bool died;
public:
   int x;
	int y;
   virtual void setName(string a)
   {
      name=a;
   }
   virtual string getName()
   {
      return name;
   }
   virtual void initDied()
   {
      died=false;
   }
   virtual void setDied()
   {
      died=true;
   }
   virtual bool isDied()
   {
      return died;
   }
};