#include <list>
#include <string>
#include <iostream>
#include "zdanie.h"
using namespace std;

string word_in;
string mas[8];
class factory
{
public:	
	~factory();
	list <Zdanie*> list;
	
	Zdanie * Add(string name, istream &is);
	Zdanie * Add_file(string name, string id, fstream &ofs);
	void Print(string type, ostream &os);
	void Save(string type, ostream &os);
};
factory::~factory()
{
	for (Zdanie *ptr : list)
		delete ptr;
}
void factory::Save(string type, ostream &os)
{	os << list.size() << endl;
	for (Zdanie *ptr : list)
	{	os << ptr->Type().name << endl;
		os <<(*ptr)<<endl;
	}
}
Zdanie * factory::Add_file(string typ,string id, fstream &ofs)
{	int i=0;
	for (zdanieType *type : get_types())
		if (type->name == typ)
		{	Zdanie *ptr = type->make();
			while (ofs >> word_in)
			{	if (word_in == typ)
				{	ofs >> word_in;
					if (word_in == id) {
						while (word_in != ";") 
							{
								mas[i] = word_in;
								ofs >> word_in;
								i++;	
							}
						list.push_back(ptr);
						ptr->set(mas, ptr);
						ptr->Print2(ofs);
						return ptr;
					}
					else{
						while (word_in != ";")
							ofs >> word_in;	}
				}	else{
					while (word_in != ";") 
						ofs >> word_in;
				}
			}			
		}
}

Zdanie * factory::Add(string name, istream &is)
{for (zdanieType *type : get_types())
		if (type->name == name)
		{
			Zdanie *ptr = type->make();
			list.push_back(ptr);
			is >> (*ptr);
			return ptr;
		}
}
void factory::Print(string type, ostream &os)
{bool flag = (type == "");
	for (Zdanie *ptr : list)
		if (flag || ptr->Type().name == type)
		{
			os << endl << (*ptr);
		}
}