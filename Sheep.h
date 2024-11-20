#include<iostream>
#include<random>
#include"Animal.h"
using namespace std;
class Sheep:public Animal
{
private:
	string color;
	int weight;
public:
	Sheep();
	Sheep(string a, string n);
	
	void setName(string a) override;
	string getName() override;

	void setColor(string a);
	string getColor();

    void setDied() override;
	bool isDied() override;

	int getWeight();
	void eat();
	
};
