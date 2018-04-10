#include <cstdint>
#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
	int Day;
	int Month;
	int Year;

	Date() {}
	Date(int d, int m, int y) : Day(d), Month(m), Year(y) {}

	bool operator==(const Date &d) const
	{
		return (Day == d.Day)
			&& (Month == d.Month)
			&& (Year == d.Year);
	}
};


istream & operator >> (istream &is, Date &d)
{
	char dot = '.';
	is >> d.Day >> dot >> d.Month >> dot >> d.Year;
	is.ignore();
	return is;
}

ostream & operator<<(ostream &os, const Date &d)
{
	return os << setfill('0') << setw(2) << d.Day << '.'
		<< setfill('0') << setw(2) << d.Month << '.'
		<< d.Year;
}