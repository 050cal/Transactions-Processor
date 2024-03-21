//Calvin Brooks
//This program reads in a CSV file with transaction information, sorts it by name, date, and price
//Input: a csv file of Transaction information is expected
//Output: sorted information of Transactions
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <new>
#include <stdexcept> 
#include "date.h"
#include "transaction.h"
using namespace std;


//parse(string record): this function parses a line of information and returns a Transaction object with that information
//parameters: string to be parsed
//return value: Transaction object
Transaction parse(string record)
{
	 //Example line: 1/2/09 6:17,Product1,1200,Mastercard,carolina,Basildon,England,United Kingdom,
	 string stringDate, stringDay, monthYear, stringTime, stringHour, stringMinutes, transactionInfo;
	 int month, year, day, hour, minutes;//these values will be assigned and used in Date constructor
	 int space, comma, slash, x, colon, y, z, w, v;//values used to find delimiters in strings
	 
	 //substr(pos, len)
	 space = record.find(" ");//finds first space
	 comma = record.find(",");//finds first comma
	 stringDate = record.substr(0, space);//grabs 1/2/09 based off following space
	 stringTime = record.substr(space + 1, (comma - (space + 1)));//grabs 6:17 based off preceding space and following comma
	 
	 
	 //below values will be passed to Date constructor, which will be passed to Transaction constructor
	 month = 1;//all months are one because its only January in SalesJan2009.csv
	 year = 9;//since we know it will always be 2009 in a SalesJan2009.csv file
	 
	 x = stringDate.size();//finding length of string stringDate to help extract the month and year
	 monthYear = stringDate.substr(2, x - 2);//grabs 2/09 from 1/2/09 based off first slash and length of stringDate
	 
	 slash = monthYear.find("/");//finding where the first slash is in 2/09
	 y = monthYear.size();//finding size of monthYear to help extract just the month
	 stringDay = monthYear.substr(0, y - 3);//since we know the year will always be 09 in SalesJan2009.csv, we can pull away '/09' or 3 char to find just the month
	 
	 
	 
	 
	 day = stoi(stringDay);//converting stringDay to an int to pass Date constructor
	 
	 colon = stringTime.find(":");//finds colon in 6:17 or stringTime string to help extract the hour
	 stringHour = stringTime.substr(0, colon);//grabs the hour based off colon
	 stringMinutes = stringTime.substr(colon + 1, 2);//grabs the minutes based off colon and the fact minutes is always 2 digits
	 
	 stringstream hourStream(stringHour);
	 stringstream minutesStream(stringMinutes);
	 
	 hourStream >> hour;//converting stringHour to an int to pass Date constructor
	 minutesStream >> minutes;//converting stringMinutes to an int to pass Date constructor

	 
	//above, we have parsed and assigned all our variables for the Date object which will eventually go into the Transaction object we will return
	//below, we will begin to parse the remaining Transaction information so we can return a Transaction object
    //we will use constructor:
    //Transaction(Date t,string pro,int pri,string pt,string n,string c,string s,string coun);
    
    z = record.size();//finding the length of the entire parameter string to help extract remaining information
    transactionInfo = record.substr((comma + 1), (z - comma));//using the index of the comma and size of the string, we can use substring to extract the remaining information
    
    int price;//this is passed to Transaction constructor
    string product, paymentType, name, city, state, country;//these variables will be assigned and used to pass to the Transaction constructor
    string newInfo, stringPrice;//this string will be reused repeatedly below to find the information of a 'shrinking' string
    
    comma = transactionInfo.find(",");//finding the first comma in the transactionInfo string
    product = transactionInfo.substr(0, comma);//extracting product from info using the position of the first comma
    
    w = transactionInfo.size();//finding size of transactionInfo to help extract remaining info
    newInfo = transactionInfo.substr(comma + 1, (w - comma));//after assigning product to variable, we will now find information following the comma, and repeat the process until finished
    
    comma = newInfo.find(",");//finding first comma in new list
    
    stringPrice = newInfo.substr(0, comma);//assigning price to variable using position of first comma in new list
    
    stringstream priceStream(stringPrice);//converting stringPrice to an int to pass Transaction constructor
    priceStream >> price;
    
    v = newInfo.size();//finding size of string to help extract remaining info needed
    newInfo = newInfo.substr(comma + 1, (v - comma));//extracting remaining info using position of first comma and length of string
    
    comma = newInfo.find(",");//finding first comma in new list
    paymentType = newInfo.substr(0, comma);//assigning payment type to variable using position of first comma in new list
    
    v = newInfo.size();//finding size of string to help extract remaining info needed
    newInfo = newInfo.substr(comma + 1, (v - comma));//extracting remaining info using position of first comma and length of string
    
    
    comma = newInfo.find(",");//finding first comma in new list
    name = newInfo.substr(0, comma);//assigning name to variable using position of comma
    
    v = newInfo.size();//finding size of string to help extract remaining info needed
    newInfo = newInfo.substr(comma + 1, (v - comma));//extracting remaining info using position of first comma and length of string
    
    comma = newInfo.find(",");//finding first comma in new list
    city = newInfo.substr(0, comma);//assigning city to variable using position of first comma in string
    
    v = newInfo.size();//finding size of string to help extract remaining info needed
    newInfo = newInfo.substr(comma + 1, (v - comma));//extracting remaining info using position of first comma and length of string
    
    comma = newInfo.find(",");//finding first comma in new list
    state = newInfo.substr(0, comma);//assigning state to variable using position of first comma in string
    
    v = newInfo.size();//finding size of string to help extract remaining info needed
    newInfo = newInfo.substr(comma + 1, (v - comma));//extracting remaining info using position of first comma and length of string
    
    comma = newInfo.find(",");//finding first comma in new list
    country = newInfo.substr(0, comma);//assigning country to variable using position of first comma in string
    
    
    //using below constructor:
    //Date(int y,int m,int d,int h,int mi);
    Date transactionDate(year, month, day, hour, minutes);//creating object from int variables assigned above
    
    //using below constructor:
    //Transaction(Date t,string pro,int pri,string pt,string n,string c,string s,string coun);
    Transaction result(transactionDate, product, price, paymentType, name, city, state, country);
    
    return result;
}


//fileSize(string filename): this function accepts a file name as a string and returns the size
//parameters: name of file
//return value: int of file size

/*Function to return the filesize in bytes*/
int fileSize(string filename)
{
	ifstream in_file(filename,ios::binary);
	in_file.seekg(0,ios::end);
	int file_size=in_file.tellg();

	return file_size;
}


//vector<Transaction> readFile(string filename): this function reads the file, handling some exceptions, before returning a vector of Transaction objects derived from file
//parameters: string of file name
//return value: a vector of Transaction objects derived from file

/*Function to readfile and return vector of Transaction
objects.*/
vector<Transaction> readFile(string filename)
{
	
	/*Handle file not found exception by throwing the string
	"filename" and also handle big file exception by 
	throwing the filesize*/
	try//try block checks for file input
	{
	    if(filename == "wrongfile.csv")
	    {
	        throw filename;//instance of file not found
	    }
	    else if(filename == "bigFile.csv")
	    {
	        int bytes = fileSize(filename);//assigning int returning function to variable bytes I will throw
	        throw bytes;
	    }
	}
	catch(string filename)//catch string for instance of file not found
	{
	    cout << "File " << filename << " not found" << endl;//output error message
	}
	catch(int bytes)//catch int for instance of file too big
	{
	    cout << "File size:" << bytes << ". Limit Exceeded" << endl;//output error message
	}
	//now that exceptions handled, we can continue with the program

	vector<Transaction> transactions;
	string line, trash;

	
	ifstream myFile(filename);
	
	int lineCount=0;
	while(getline(myFile,line))
	{
		//Parse the line here ignoring the first line
		if(lineCount>0)
		{
			//we are reading in the file SalesJan2009.csv line by line
			//this adds a transaction to the vector using parse function which returns a class Transaction
			//Transaction parse(string record) function above
			transactions.push_back(parse(line));
		}
		lineCount++;
	}
	
	

	return transactions;
	
}

//void sortAndPrint(vector<T> records,int size): this function sorts and prints a passed vector of template data type
//parameters: vector of template data type and int of size of vector
//return value: void

/*Template function to sort and print*/
template <class T>
void sortAndPrint(vector<T> records,int size)
{
    //using bubble sort to sort vector
    for(int i = 0; i < (size - 1); i++)
    {
        for(int j = 0; j < (size - i - 1); j++)
        {
            if(records[j] > records[j + 1])//'>' operator is overloaded for class Date which may be passed
            {
                //we can set objects of one class equal to another in the case Date is passed
                T temp = records[j];//assigning higher value to temp value of template datatype T
                records[j] = records[j + 1];//assigning value of higher element to this element
                records[j + 1] = temp;//assigning saved value of lower element to the previously higher element
            }
        }
    }
    
    for(int k = 0; k < size; k++)
    {
        cout << records[k] << endl;//now that they are sorted, we can output them, in the case of a Date, '<<' is overloaded for the class
    }
}




int main(int argc,char * argv[])
{
	
	//ASSIGNING STRING VARIABLES BELOW-SKELETON CODE
	//Wrong file name
	string wrongFile="wrongfile.csv";

	//Big file name
	string bigFile="bigFile.csv";

	//Correct file name
	string file="SalesJan2009.csv";

	
	//vector to hold all the transactions
	vector<Transaction> transactions;

	
	//HANDLE EXCEPTIONS FOR BIG FILE OR FILE NOT FOUND BELOW
	cout<<"Reading wrongfile.csv"<<endl;//output message
	transactions=readFile(wrongFile);//

	cout<<"Reading bigFile.csv"<<endl;
	transactions=readFile(bigFile);


	cout<<"Reading SalesJan2009.csv"<<endl;//output message
	transactions= readFile(file);//assigns the vector returning function to the vector made above

	//OUTPUT MESSAGE
	cout <<"File read."<<transactions.size()<<" transactions returned"<<endl;

	
	try//try-catch block for bad allocation
	{
	    while(true)
	    {
	        new int[100000000ul];
	    }
	}
	catch(const bad_alloc& badAlloc)//using what() function of <new> library
	{
	    cout << "Allocation failed." << badAlloc.what() << endl;//output error message
	}
	
	
	vector<string> names;
	vector<int> price;
	vector<Date> dates;
	//sort by name
	try//try-catch block for the length error of vector
	{
	    names.resize(names.max_size()+1);
	    price.resize(price.max_size()+1);
	    dates.resize(dates.max_size()+1);
	}
	catch(const std::length_error& lengthError)//print lengthError using #include <stdexcept>
	{
	    cout << "Length error:" << lengthError.what() << endl;//output error message
	}
	names.resize(25);//resizing vector
	price.resize(25);//resizing vector
	dates.resize(25);//resizing vector
	

	try//try-catch block to determine if value is between 1 and 25
	{
	  	int number;
	    cout <<"Enter the number of records to sort(1-25):";
	    cin>>number;
	    if(number <= 0)
	    {
	        throw number;
	    }
	    else if(number > 25)
	    {
	        throw number;
	    }
	    
	    //ADDING VECTOR POPULATION PORTION HERE TO AVOID COMPILATION ERROR
	    //Populating the vectors from transactions
	    for(int i=0;i<number;i++)
	    {
	        names.at(i)=transactions[i].getName();
	        price.at(i)=transactions[i].getPrice();
	        dates.at(i)=transactions[i].getDate();
	        
	    }
	    
	    sortAndPrint(names,number);
	    sortAndPrint(dates,number);
	    sortAndPrint(price,number);
	    
	}
	catch(int number)
	{
	    if(number <= 0)
	    {
	        cout << "Number of records to sort below the minimum vector size:vector" << endl;
	        return 0;//program does not continue to next statement if out of range
	    }
	    if(number > 25)
	    {
	        cout << "Number of records to sort exceeded the maximum vector size:vector" << endl;
	        return 0;//program does not continue to next statement if out of range
	    }
	}
	
	


	return 0;
}