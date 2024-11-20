#include<iostream>
#include"Sheep.cpp"
using namespace std;
class Wolve: public Animal
{
private:
	int age;
	int energy;
public:
	Wolve(){}
	Wolve(string a,int n);

	void setName(string a) override;
	string getName() override;

	void setAge(int a);
	int getAge();

	void setEnergy(int a);
	int getEnergy();
	void addEnergy(int a);

	void energeWithDied(int &wcount,string (&area)[8][8]);
	bool isDied() override;

	void eat(Sheep &s,int len);
};
