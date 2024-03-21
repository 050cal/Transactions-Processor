//Calvin Brooks
//This program reads in a CSV file with transaction information, sorts it by name, date, and price
//Input: a csv file of Transaction information is expected
//Output: sorted information of Transactions
#include <iostream>
using namespace std;
/*Date class to hold the full date and time*/


//Date class: this class contains information relating to a date
//Constructors: one to assign all members & an empty default
//public functions:
//bool operator>(Date& other)
//ostream& operator<<(ostream& obj,Date d)
//static members: none

class Date
{
	//friend function to overlaed insertion operator to print the date
	friend ostream& operator<<(ostream& obj,Date d);
private:
	int year;
	int month;
	int day;
	int hour;
	int min;
public:
	Date(int y,int m,int d,int h,int mi)
	{
		year=y;
		month=m;
		day=d;
		hour=h;
		min=mi;
	}
	Date()
	{
		//empty as provided-works with assignment
	}

	/*overloading > operator to check which date is later. 
	Date returned by this function is the later one*/
	bool operator>(Date& other)
	{
		if(year>other.year)
			return true;
		else if(year==other.year && month>other.month )
			return true;
		else if(year==other.year && month==other.month && day>other.day)
			return true;
		else if(year==other.year && month==other.month && day==other.day && hour>other.hour)
			return true;
		else if(year==other.year && month==other.month && day==other.day && hour==other.hour && min>other.min)
			return true;
		else
			return false;
	}
	virtual ~Date(){}
};


ostream& operator<<(ostream& obj,Date d)
{
	obj<<d.month<<"/"<<d.day<<"/"<<d.year<<" "<<d.hour<<":"<<d.min;
	return obj;
}