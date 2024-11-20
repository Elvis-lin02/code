#include<iostream>
#include<random>
#include"Sheep.h"
using namespace std;
	Sheep::Sheep()
	{
		Animal::initDied();
		default_random_engine e;
        uniform_int_distribution<int> u(5,30);  //左闭右闭区间
        e.seed(time(0));
		weight=u(e);
	}
	Sheep::Sheep(string a, string n)
	{
		Animal::setName(a);
		color=n;
		Animal::initDied();
		default_random_engine e;
        uniform_int_distribution<int> u(5,30);  //左闭右闭区间
        e.seed(time(0));
		weight=u(e);
	}
	void Sheep::setName(string a) 
	{
		Animal::setName(a);
	}
	string Sheep::getName()
	{
		return Animal::getName();
	}

	void Sheep::setColor(string a)
	{
		color=a;
	}
	string Sheep::getColor()
	{
		return color;
	}

    void Sheep::setDied()
	{
		Animal::setDied();
	}
	bool Sheep::isDied()
	{
		return Animal::isDied();
	}

	int Sheep::getWeight()
	{
		return weight;
	}

	
	void Sheep::eat()
	{
		cout<<"叫"<<Animal::getName()<<color<<"的羊吃了草";
		weight++;
	}
