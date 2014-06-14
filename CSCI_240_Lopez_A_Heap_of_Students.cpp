#include<iostream>
#include<fstream>
#include<string>
#include <string.h>

//visual studio exception
//#define _CRT_SECURE_NO_WARNINGS

//Corrdinates for information for the picking_out_substrings function. The data argument part
#define SURNAME 1
#define GIVEN_NAME 2
#define STREET_ADDRESS 3
#define CITY 4
#define STATE 5
#define ZIP_CODE 6
#define DATE_OF_BIRTH 7
#define GRADUATION_DATE 8
#define GPA 9
#define CREDIT_HOURS_COMPLETE 10

using namespace std;

//DONE
string picking_out_substrings(float, float);

void printinfo(string,string,string,string,string,string,string);

void print_first_and_last_name (string,string);
														/*DATE CLASS*/

//DONE
class DATE
{
	private:
		string date;
	public:
			
		DATE();//constructor

		//setter
		void setdate(float, float);

		//getter
		string getdate();//the final date in one nice string

};

DATE::DATE()
{
	DATE::date = "mm/dd/yyy";

}

void DATE::setdate(float student_number, float data)//student student_number
{
		DATE::date = picking_out_substrings(student_number, data);
}

string DATE::getdate()
{
	return (DATE::date);	
}

//======================================================================================================================
														/*ADDRESS CLASS*/
class ADDRESS
{
	private:
			string street_address;
			string city;
			string state;
			string zcode;
			string address;
	public:
			ADDRESS();//constructor
			
			//setters
			void setstreet_address (float, float);
			void setcity (float, float);
			void setstate (float, float);
			void setzcode (float, float);

			void setcomplete_address();

			//getters
			//string getstreet_address ();
			//string getcity ();
			//string getstate ();
			//string getzcode ();

			string getcomplete_address();
};

ADDRESS::ADDRESS()
{
	ADDRESS::street_address = "street address";
	ADDRESS::city = "city";
	ADDRESS::state = "state";
	ADDRESS::zcode = "zip code";
}

//street functions
void ADDRESS::setstreet_address(float student_number, float data)
{
	ADDRESS::street_address = picking_out_substrings(student_number, data);
}
//string ADDRESS::getstreet_address()
//{
//	return ADDRESS::street_address;
//}

//city functions
void ADDRESS::setcity(float student_number, float data)
{
	ADDRESS::city = picking_out_substrings(student_number, data);
}
//string ADDRESS::getcity()
//{
//	return ADDRESS::city;
//}

//state functions
void ADDRESS::setstate(float student_number, float data)
{
	ADDRESS::state = picking_out_substrings(student_number, data);
}
//string ADDRESS::getstate()
//{
//	return ADDRESS::state;
//}

//zip code functions
void ADDRESS::setzcode(float student_number, float data)
{
	ADDRESS::zcode = picking_out_substrings(student_number, data);
}
//string ADDRESS::getstate()
//{
//	return ADDRESS::zcode;
//}

//address functions
void ADDRESS::setcomplete_address()
{
	ADDRESS::address = ADDRESS::street_address + "," + ADDRESS::city + "," + ADDRESS::state + " " + ADDRESS::zcode;
}
string ADDRESS::getcomplete_address()
{
	return ADDRESS::address;
}

//======================================================================================================================
														/*STUDENT CLASS*/
class STUDENT
{
	private:
			string surname;
			string givenname;
			string address;
			string dob;//the result of (birth: day, month, & year) into one nice string
			string agd;//the result of (graduation(expected): day, month, & year) into one nice string
			string gpa;
			string credithours;

			//instances of both class, a total of 3
			DATE DOB;
			DATE AGD;
			ADDRESS homeaddress;

	public:

			STUDENT();//constructor
			//setters
			void setsurname (float);
			void setgivenname(float);
			void setaddress(float);
			void setdob (float);
			void setagd (float);
			void setgpa (float);
			void setcredithours (float);
			//getters
			string getsurname();
			string getgivenname();
			string getaddress();
			string getdob();
			string getagd();
			string getgpa();
			string getcredithours();
//				     									          \ /     
			~STUDENT();//KILLS THE STUDENT                        0 0      _______________
//		    									                 .   . ~~~| "MUHAHAHAHA!!"|
//				                                                  ...     |_______________|
};

// pull gpa and credit hours out of text file in this function.
STUDENT::STUDENT()
{
	STUDENT::givenname = "first name";
	STUDENT::surname = "sur name";
	STUDENT::address = "address";
	STUDENT::dob = "mm/dd/yyyy";
	STUDENT::agd = "mm/dd/yyy";
	STUDENT::gpa = "#.##";
	STUDENT::credithours = "###";

}

//surname functions
void STUDENT::setsurname(float student_number)
{
	STUDENT::surname = picking_out_substrings(student_number, 1);
}
string STUDENT::getsurname()
{
	return STUDENT::surname;
}

//given name functions
void STUDENT::setgivenname(float student_number)
{
	STUDENT::givenname = picking_out_substrings(student_number, GIVEN_NAME);
}
string STUDENT::getgivenname()
{
	return STUDENT::givenname;
}

//address functions
void STUDENT::setaddress(float student_number)
{
	homeaddress.setstreet_address(student_number, STREET_ADDRESS);
	homeaddress.setcity(student_number, CITY);
	homeaddress.setstate(student_number, STATE);
	homeaddress.setzcode(student_number, ZIP_CODE);

	homeaddress.setcomplete_address();
}
string STUDENT::getaddress()
{
	return STUDENT::address = homeaddress.getcomplete_address();
}

//date of birth functions
void STUDENT::setdob (float student_number)
{
	DOB.setdate(student_number, DATE_OF_BIRTH);	
}
string STUDENT::getdob()
{
	STUDENT::dob = DOB.getdate();
	return STUDENT::dob;
}

//Graduation date functions
void STUDENT::setagd (float student_number)
{
	AGD.setdate(student_number, GRADUATION_DATE);	
}
string STUDENT::getagd()
{
	STUDENT::agd = AGD.getdate();
	return STUDENT::agd;
}

//GPA functions
void STUDENT::setgpa (float student_number)
{
	STUDENT::gpa = picking_out_substrings(student_number, GPA);
}
string STUDENT::getgpa ()
{
	return STUDENT::gpa;
}

//completed credit hour functions
void STUDENT::setcredithours(float student_number)
{
	STUDENT::credithours = picking_out_substrings(student_number, CREDIT_HOURS_COMPLETE);
}
string STUDENT::getcredithours()
{
	return STUDENT::credithours;
}

//destructor function hahahaha!!!!
STUDENT::~STUDENT()
{

}
//======================================================================================================================
int main()
{
	STUDENT s[51];//a heap of students
	int student_number;
	string surname,givenname,address,dateofbirth,graduationdate,gradepointaverage,credithourscompleted;
			cout<<"Surname,GivenName,StreetAddress,City,State,ZipCode,";
		cout<<"Date of Birth,Graduation date,GPA,Credit Hours Complete"<<endl<<endl;
	for (student_number=1;student_number<=50;student_number++)//printing all the info
	{
		//setters
		s[student_number].setsurname(student_number);
		s[student_number].setgivenname(student_number);
		s[student_number].setaddress(student_number);
		s[student_number].setdob(student_number);
		s[student_number].setagd(student_number);
		s[student_number].setgpa(student_number);
		s[student_number].setcredithours(student_number);

		//getters
		surname = s[student_number].getsurname();
		givenname = s[student_number].getgivenname();
		address = s[student_number].getaddress();
		dateofbirth = s[student_number].getdob();
		graduationdate = s[student_number].getagd();
		gradepointaverage = s[student_number].getgpa();
		credithourscompleted = s[student_number].getcredithours();

		printinfo(surname,givenname,address,dateofbirth,graduationdate,gradepointaverage,credithourscompleted);
		

	}//end for loop
	cout<<endl<<"\t\t\t Simpler List (first and last names)."<<endl<<endl;
	for (student_number=1;student_number<=50;student_number++)//prints the simpler list with first and last name
	{
		//setters
		s[student_number].setsurname(student_number);
		s[student_number].setgivenname(student_number);
		s[student_number].setaddress(student_number);
		s[student_number].setdob(student_number);
		s[student_number].setagd(student_number);
		s[student_number].setgpa(student_number);
		s[student_number].setcredithours(student_number);

		//getters
		surname = s[student_number].getsurname();
		givenname = s[student_number].getgivenname();
		address = s[student_number].getaddress();
		dateofbirth = s[student_number].getdob();
		graduationdate = s[student_number].getagd();
		gradepointaverage = s[student_number].getgpa();
		credithourscompleted = s[student_number].getcredithours();
		
		print_first_and_last_name(surname,givenname);
	}//end for loop


	
	return 0;
}

string picking_out_substrings(float student_number, float data)//student_number represents which student data represents which substring to pick out from the text
{

	string line;
	ifstream fin;
	string substring;
	string finalsubstring;
	char linearray[400];
	 float i=1;//starts at the first student
	


    fin.open("A_Heap_of_Students_information.txt");
	if (fin.fail())
		cout << "Unable to open file" <<endl<<endl;

	while (!fin.eof())
	{
		
		getline(fin,line);
		
		strcpy_s(linearray, line.c_str());//copies the string into an arry for tokenizing

		char * subarray;

  subarray = strtok(linearray,",");


  while (subarray != NULL)
  {
		subarray = strtok (NULL, ",");
		if ((i-data)/(11*student_number) == 1|| 0)//determines which student to pick out and there are 11 tokens in a row
		{
			//this is the dob
			finalsubstring = subarray;
			
 		
		//cout<<"---------------------------------------------------"<<endl;
		}
	i++;
  }

	}
	
		fin.close();
		//cout<<finalsubstring<<endl;
		return finalsubstring;
}

void printinfo(string surname,string givenname,string address,string dateofbirth,string graduationdate,
			   string gradepointaverage, string credithourscompleted)
{
	cout<<surname<<","<<givenname<<","<<address<<",";
		cout<<dateofbirth<<","<<graduationdate<<","<<gradepointaverage<<","<<credithourscompleted<<endl<<endl;
}

void print_first_and_last_name (string surname, string givenname)
{
	cout<<"First name: "<<givenname<<endl<<"Last name: "<<surname<<endl<<endl; 
}