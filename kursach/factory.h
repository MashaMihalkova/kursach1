#include <list>
#include <string>
#include <iostream>
#include "date.h"

using namespace std;

class Zdanie;
struct zdanieType;

template <class T>
Zdanie * ZdanMaker() { return new T; }

list <zdanieType*> & get_types()
{
	static list <zdanieType*> types;
	return types;
}

struct zdanieType
{
	int count;
	string name;
	Zdanie *(*make)();
	zdanieType(const char *n, Zdanie *(*m)())
		: name(n), make(m), count(0) {
		get_types().push_back(this);
	}
};
class Zdanie {
	string description;
	string color;
	int floor;
	int num_flat;
	int area;
	string address;
	Date  year_completion;
public:
	virtual const zdanieType & Type() const = 0;
	virtual const Date & BirthDate() const {return  year_completion;}

	//virtual void Print1(string typ, factory *f) const;
	virtual void Print(ostream &os = cout) const;
	virtual void Read(istream &is);
	virtual void Save(ostream &os);

	virtual ~Zdanie() {}
};
void Zdanie::Save(ostream &os) 
{
	os << description << endl;
	os << color << endl;
	os << floor << endl;
	os << num_flat << endl;
	os << area << endl;
	os << address << endl;
	os << year_completion << endl;
}
void Zdanie::Read(istream &is)
{
	//getline(is, description);
	//getline(is, color);
	cout << "description: "; cin >> description;
	cout << "color: "; cin >> color;
	cout << "floor: "; cin >> floor;
	cout << "num_flat: "; cin >> num_flat;
	cout << "area: "; cin >> area;
	//getline(is, address);
	cout << "address: "; cin >> address;
	cout << "year_completion: "; cin >> year_completion;
}
void Zdanie::Print(ostream &os) const
{
		os << "description: " << description << endl;
		os << "color: " << color << endl;
		os << "floor: " << floor << endl;
		os << "num_flat: " << num_flat << endl;
		os << "area: " << area << endl;
		os << "address: " << address << endl;
		os << "year_completion: " << year_completion << endl;

};
/*void Zdanie::Print1(string typ, factory *f) const
{
	for (Zdanie *ptr : (*f).list)
		if (ptr->Type().name == typ)
		{
			cout<<(*ptr);
		}
};
*/
class panel :public Zdanie {
	static zdanieType type;
public:
	panel() { ++type.count; }
	void Print(ostream &os);
	//void Print1(string typ,factory *f);
	void Save(ostream &os);
	const zdanieType & Type() const { return type; }
	//const Date & BirthDate() const { return year_completion; }
};
class cottage :public Zdanie {
	static zdanieType type;
public:
	cottage() { ++type.count; }
	const zdanieType & Type() const { return type; }
	void Print(ostream &os );
	//void Print1(string typ, factory *f);
	void Save(ostream &os);
};
void panel::Print(ostream &os){
Zdanie::Print(os);
}
/*void panel::Print1(string typ,factory *f) {
	//Zdanie::Print(os);
}
void cottage::Print1(string typ,factory *f) {

	//Zdanie::Print(os);
}*/
void panel::Save(ostream &os) {
	Zdanie::Save(os);
}
void cottage::Save(ostream &os) {
	Zdanie::Save(os);
}
void cottage::Print(ostream &os) {
	Zdanie::Print(os);
}

//const Date Zdanie::empty_date(0, 0, 0);
zdanieType panel::type("panel", &ZdanMaker<panel>);
zdanieType cottage::type("cottage", &ZdanMaker<cottage>);


istream & operator >> (istream &is, Zdanie &d)
{
	d.Read(is);
	return is;
}
ostream & operator<<(ostream &os, const Zdanie &d)
{
	d.Print(os);
	return os;
}
