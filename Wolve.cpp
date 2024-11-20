#include<iostream>
#include"Wolve.h"
using namespace std;
Wolve::Wolve(string a,int n)
{
	Animal::initDied();
	Animal::setName(a);
	age=n;
}
void Wolve::setName(string a)
{
	Animal::setName(a);
}
string Wolve::getName()
{
	return Animal::getName();
}
void Wolve::setAge(int a)
{
	age=a;
}
int Wolve::getAge()
{
	return age;
}
void Wolve::setEnergy(int a)
{
	energy=a;
}
int Wolve::getEnergy()
{
	return energy; 
}
void Wolve::addEnergy(int a)
{
	energy+=a;
	printf("投喂成功：%d kg",a);
}
void Wolve::energeWithDied(int &wcount,string (&area)[8][8])
{
	if(energy==0)
	{
		Animal::setDied();
	}
	wcount--;
	area[x][y]={0};
}
bool Wolve::isDied()
{
	return Animal::isDied();
}
void Wolve::eat(Sheep &s,int len)
{
	if(energy>=len)
	{
		cout<<age<<"岁的"<<Animal::getName()<<"狼要吃";
		cout<<s.getColor()<<"的"<<s.getName()<<"羊"<<endl;
		s.setDied();
		energy+=(int)s.getWeight();
	}
	else
	{
		cout<<"能量不够捕食,能量减一";
		energy--;
	}
}

