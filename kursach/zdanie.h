#include <list>
#include <string>
#include <iostream>
#include "factory.h"
using namespace std;

class factory
{
private:
	//list <Zdanie*> list;

public:
	//factory(istream &is);
	~factory();

	list <Zdanie*> list;

	Zdanie * Add(string name, istream &is);
	void Print(string type, ostream &os);
	void Save(string type, ostream &os);

};
factory::~factory()
{
	for (Zdanie *ptr : list)
		delete ptr;
}
/*factory::factory(istream &is)
{
	int num;
	is >> num;
	is.ignore();
	for (int i = 0; i<num; ++i)
	{
		string name;
		getline(is, name);
		Add(name, is);
	}
}*/
void factory::Save(string type, ostream &os)
{
	os << list.size() << endl;
	for (Zdanie *ptr : list)
	{
		os << ptr->Type().name << endl;
		os <<(*ptr)<<endl;
	}
}
Zdanie * factory::Add(string name, istream &is)
{
	for (zdanieType *type : get_types())
		if (type->name == name)
		{
			Zdanie *ptr = type->make();
			list.push_back(ptr);
			is >> (*ptr);
			//is << (*ptr);
			return ptr;
		}
}
void factory::Print(string type, ostream &os)
{
	bool flag = (type == "");
	for (Zdanie *ptr : list)
		if (flag || ptr->Type().name == type)
		{
			os << endl << (*ptr);
		}
}