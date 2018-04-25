#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "date.h"
using namespace std;
class Zdanie;
struct zdanieType;
template <class T>
Zdanie * ZdanMaker() { return new T; }
list <zdanieType*> & get_types()
{static list <zdanieType*> types;
	return types;
}
struct zdanieType
{int count;
	string name;
	Zdanie *(*make)();
	zdanieType(const char *n, Zdanie *(*m)())
		: name(n), make(m), count(0) {
		get_types().push_back(this);
	}
};
class Zdanie {
protected:
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
	virtual void Print(ostream &os = cout) const;
	virtual void Print2(fstream &os) const;
	virtual void Read(istream &is);
	virtual void Save(ostream &os);
	virtual void set(string *mas, Zdanie *d);
	virtual ~Zdanie() {}
};
void Zdanie::Save(ostream &os) 
{	os << description << endl;
	os << color << endl;
	os << floor << endl;
	os << num_flat << endl;
	os << area << endl;
	os << address << endl;
	os << year_completion << endl;
}
void Zdanie::Read(istream &is)
{	cout << "description: "; cin >> description;
	cout << "color: "; cin >> color;
	cout << "floor: "; cin >> floor;
	cout << "num_flat: "; cin >> num_flat;
	cout << "area: "; cin >> area;
	cout << "address: "; cin >> address;
	cout << "year_completion: "; cin >> year_completion;
}
void Zdanie::set(string *mas,Zdanie *d)
{	d->description = mas[1];
	d->color = mas[2];
	std::istringstream ist(mas[3]);
	ist >> d->floor;
	std::istringstream ist1(mas[4]);
	ist1 >> d->num_flat;
	std::istringstream ist2(mas[5]);
	ist2 >> d->area;
	d->address = mas[6];
	int day, mo, ye;
	char dat[11]="\0";
	string date;
	date = mas[7];
	strcpy(dat, date.c_str());
	day=(dat[0]-'0')*10 + dat[1]-'0';	
	mo= (dat[3] - '0') * 10 + dat[4] - '0';
	ye=(dat[6] - '0') * 1000 + (dat[7] - '0')*100+ (dat[8] - '0') * 10 + dat[9] - '0';
	d->year_completion=Date::Date(day, mo, ye);
};
void Zdanie::Print(ostream &os) const
{		os << "description: " << description << endl;
		os << "color: " << color << endl;
		os << "floor: " << floor << endl;
		os << "num_flat: " << num_flat << endl;
		os << "area: " << area << endl;
		os << "address: " << address << endl;
		os << "year_completion: " << year_completion << endl;

};
void Zdanie::Print2(fstream &os) const
{	cout << "description: " << description << endl;
	cout << "color: " << color << endl;
	cout << "floor: " << floor << endl;
	cout << "num_flat: " << num_flat << endl;
	cout << "area: " << area << endl;
	cout << "address: " << address << endl;
	cout << "year_completion: " << year_completion << endl;
}
class panel :public Zdanie {
	static zdanieType type;
public:
	panel() { ++type.count; }
	void Print(ostream &os);
	void Print2(fstream &os);
	void Save(ostream &os);
	const zdanieType & Type() const { return type; }
};
class brick :public Zdanie {
	static zdanieType type;
public:
	brick() { ++type.count; }
	void Print(ostream &os);
	void Print2(fstream &os);
	void Save(ostream &os);
	const zdanieType & Type() const { return type; }
};
class brick_monolithic :public Zdanie {
	static zdanieType type;
public:
	brick_monolithic() { ++type.count; }
	void Print(ostream &os);
	void Print2(fstream &os);
	void Save(ostream &os);
	const zdanieType & Type() const { return type; }
};
class cottage :public Zdanie {
	static zdanieType type;
public:
	cottage() { ++type.count; }
	const zdanieType & Type() const { return type; }
	void Print(ostream &os );
	void Print2(fstream &os);
	void Save(ostream &os);
};

void brick::Print(ostream &os) {Zdanie::Print(os);}
void brick::Print2(fstream &os) {Zdanie::Print2(os);}
void brick::Save(ostream &os) {Zdanie::Save(os);}
void brick_monolithic::Print(ostream &os) {Zdanie::Print(os);}
void brick_monolithic::Print2(fstream &os) {Zdanie::Print2(os);}
void brick_monolithic::Save(ostream &os) {Zdanie::Save(os);}
void panel::Print(ostream &os){Zdanie::Print(os);}
void panel::Print2(fstream &os) {Zdanie::Print2(os);}
void panel::Save(ostream &os) {Zdanie::Save(os);}
void cottage::Save(ostream &os) {Zdanie::Save(os);}
void cottage::Print(ostream &os) {Zdanie::Print(os);}
void cottage::Print2(fstream &os) {Zdanie::Print2(os);}

zdanieType panel::type("panel", &ZdanMaker<panel>);
zdanieType cottage::type("cottage", &ZdanMaker<cottage>);
zdanieType brick::type("brick", &ZdanMaker<brick>);
zdanieType brick_monolithic::type("brick_monolithic", &ZdanMaker<brick_monolithic>);

istream & operator >> (istream &is, Zdanie &d)
{d.Read(is);	return is;}
ostream & operator<<(ostream &os, const Zdanie &d)
{d.Print(os);	return os;}