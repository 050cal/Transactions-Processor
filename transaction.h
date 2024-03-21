//Calvin Brooks
//This program reads in a CSV file with transaction information, sorts it by name, date, and price
//Input: a csv file of Transaction information is expected
//Output: sorted information of Transactions
/*Transaction class to hold each transaction*/
#include <iostream>
using namespace std;

//Transaction class: this class contains information relating to a transaction, and contains class Date as a member
//Constructors: one to assign all members
//public functions:
//int getPrice();
//string getName();
//Date getDate();
//static members: none

class Transaction
{
private:
	//contains class Date from date.h
	Date transactionDate;//Date of transaction 
	string product;//Product
	int price;//Price 
	string paymentType;//Payment type of transaction like Mastercard, visa
	string name;//Name of person making transaction
	string city;//City of the person
	string state;//State 
	string country;//country

public:
	//this constructor is used to create objects from the info parsed from SalesJan2009.csv
	Transaction(Date t,string pro,int pri,string pt,string n,string c,string s,string coun):transactionDate(t)
	{
		product=pro;
		price=pri;
		paymentType=pt;
		name=n;
		city=c;
		state=s;
		country=coun;
	}
	/*Transaction()
	{

	}*/
	
	//accessor function returns private member price
	int getPrice()
	{
		return price;
	}
	//accessor function returns private member name
	string getName()
	{
		return name;
	}
	//accessor function returns private member date
	Date getDate()
	{
		return transactionDate;
	}
	virtual ~Transaction(){}


};
