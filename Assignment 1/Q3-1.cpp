#include<iostream>
using namespace std;

class Employee{
	protected:
		string employeeName, employeeID;
	public:
		virtual void getInfo(){
			cout << "Enter Employee Name:\t";
			cin >> employeeName;
			cout << "Enter Employee ID:\t";
			cin >> employeeID;
		}
		virtual void displayInfo(){
			cout << "Employee Name:\t" << employeeName << endl;
			cout << "Employee ID:\t" << employeeID << endl;
		}
};

class Employee2 : protected Employee{
	protected:
		double amountPaid;
		int paymentPeriod;
	public:
		void getInfo() override{
			Employee :: getInfo();
			cout << "Enter Amount Paid:\t";
			cin >> amountPaid;
			cout << "Enter Payment Period in Days:\t";
			cin >> paymentPeriod;
		}
		void displayInfo() override{
			Employee :: displayInfo();
			cout << "Amount Paid:\t" << amountPaid << endl;
			cout << "Enter Payment Period in Days:\t" << paymentPeriod << endl;
		}
};

class Manager : protected Employee2{
	protected:
		string dept;
	public:
		void getInfo() override{
			Employee2 :: getInfo();
			cout << "Enter Department:\t";
			cin >> dept;
		}
		void displayInfo() override{
			Employee2 :: displayInfo();
			cout << "Department:\t" << dept << endl;
		}
};

class Scientist : protected Employee2{
	protected:
		string field;
	public:
		void getInfo() override{
			Employee2 :: getInfo();
			cout << "Enter Field:\t";
			cin >> field;
		}
		void displayInfo() override{
			Employee2 :: displayInfo();
			cout << "Field:\t" << field << endl;
		}
};

class Laborer : protected Employee2{
	protected:
		string worksite;
	public:
		void getInfo() override{
			Employee2 :: getInfo();
			cout << "Enter Worksite:\t";
			cin >> worksite;
		}
		void displayInfo() override{
			Employee2 :: displayInfo();
			cout << "Worksite:\t" << worksite << endl;
		}
};

int main(){
	cout << "\tOriginal Base Class:\n";
	Employee e1;
	e1.getInfo();
	cout << endl;
	e1.displayInfo();
	
	cout << endl <<  "\tNew Derived Class:\n";
	Employee2 e2;
	e2.getInfo();
	cout << endl;
	e2.displayInfo();
	
	cout << endl << "\tManager Class:\n";
	Manager m1;
	m1.getInfo();
	cout << endl;
	m1.displayInfo();
	
	cout << endl << "\tScientist Class:\n";
	Scientist s1;
	s1.getInfo();
	cout << endl;
	s1.displayInfo();
	
	cout << endl << "\tLaborer Class:\n";
	Laborer l1;
	l1.getInfo();
	cout << endl;
	l1.displayInfo();
}
