#include<iostream>
#include<conio.h>
using namespace std;

class TollBooth{
	private:
		unsigned int noOfCars;
		double cashCollected;
	public:
		TollBooth(){
			noOfCars = 0;
			cashCollected = 0;	
		}
		void payingCar(){
			noOfCars++;
			cashCollected += 0.5;
		}
		void noPayingCar(){
			noOfCars++;
		}
		void display(){
			cout << "Total Numbers of Cars Passed: " << noOfCars << endl;
			cout << "Total Cash Collected: " << cashCollected << endl;
		}
};

int main(){
	TollBooth t;
	cout << "Press y for a Paying Car and n for a Non-Paying Car\n";
	char input;
	while(input != 27){
		input = _getch();
		switch(input){
			case 'y':
				cout << "Toll Paid!\n";
				t.payingCar();
				break;
				
			case 'n':
				cout << "Toll NOT Paid!\n";
				t.noPayingCar();
				break;
				
			case 27:
				cout << "Simulation Ended\n";
				break;
			default:
				cout << "Invalid Input. Try Again" << endl;
		}
	}
	cout << endl;
	t.display();
}
