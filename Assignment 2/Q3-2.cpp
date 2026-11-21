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

class Compensation : protected Employee{
	protected:
		double amountPaid;
		int paymentPeriod;
	public:
		void getCompInfo(){
			cout << "Enter Amount Paid:\t";
			cin >> amountPaid;
			cout << "Enter Payment Period in Days:\t";
			cin >> paymentPeriod;
		}
		void displayCompInfo(){
			cout << "Amount Paid:\t" << amountPaid << endl;
			cout << "Enter Payment Period in Days:\t" << paymentPeriod << endl;
		}
};

class Manager : protected Employee{
	protected:
		string dept;
	public:
		void getInfo() override{
			Employee :: getInfo();
			cout << "Enter Department:\t";
			cin >> dept;
		}
		void displayInfo() override{
			Employee :: displayInfo();
			cout << "Department:\t" << dept << endl;
		}
};

class Manager2 : protected Manager, protected Compensation{
	public:
		void getInfo() override{
			Manager :: getInfo();
			Compensation :: getCompInfo();
		}
		void displayInfo() override{
			Manager :: displayInfo();
			Compensation :: displayCompInfo();
		}
};

class Scientist : protected Employee{
	protected:
		string field;
	public:
		void getInfo() override{
			Employee :: getInfo();
			cout << "Enter Field:\t";
			cin >> field;
		}
		void displayInfo() override{
			Employee :: displayInfo();
			cout << "Field:\t" << field << endl;
		}
};

class Scientist2 : protected Scientist, protected Compensation{
	public:
		void getInfo() override{
			Scientist :: getInfo();
			Compensation :: getCompInfo();
		}
		void displayInfo() override{
			Scientist :: displayInfo();
			Compensation :: displayCompInfo();
		}
};

class Laborer : protected Employee{
	protected:
		string worksite;
	public:
		void getInfo() override{
			Employee :: getInfo();
			cout << "Enter Worksite:\t";
			cin >> worksite;
		}
		void displayInfo() override{
			Employee :: displayInfo();
			cout << "Worksite:\t" << worksite << endl;
		}
};

class Laborer2 : protected Laborer, protected Compensation{
	public:
		void getInfo() override{
			Laborer :: getInfo();
			Compensation :: getCompInfo();
		}
		void displayInfo() override{
			Laborer :: displayInfo();
			Compensation :: displayCompInfo();
		}
};

int main(){
	cout << "\tBase Class:\n";
	Employee e1;
	e1.getInfo();
	cout << endl;
	e1.displayInfo();
	
	cout << endl << "\tBase Manager Class:\n";
	Manager m1;
	m1.getInfo();
	cout << endl;
	m1.displayInfo();
	
	cout << endl << "\tDerived Manager Class:\n";
	Manager2 m2;
	m2.getInfo();
	cout << endl;
	m2.displayInfo();
	
	cout << endl << "\tBase Scientist Class:\n";
	Scientist s1;
	s1.getInfo();
	cout << endl;
	s1.displayInfo();
	
	cout << endl << "\tDerived Scientist Class:\n";
	Scientist2 s2;
	s2.getInfo();
	cout << endl;
	s2.displayInfo();
	
	cout << endl << "\tBase Laborer Class:\n";
	Laborer l1;
	l1.getInfo();
	cout << endl;
	l1.displayInfo();
	
	cout << endl << "\tDerived Laborer Class:\n";
	Laborer2 l2;
	l2.getInfo();
	cout << endl;
	l2.displayInfo();
}
