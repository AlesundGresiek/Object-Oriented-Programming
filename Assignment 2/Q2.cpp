#include<iostream>
using namespace std;

class Sterling{
	protected:
		int sterling;
	public:
		virtual void getInfo(){
			cout << "Enter Sterlings:\t";
			cin >> sterling;
			cout << endl;
		}
		virtual void displayInfo(){
			cout << "Sterlings:\t $" << sterling;
		}
};
class Sterfrac : protected Sterling{
	protected:
		int eighths;
	public:
		void getInfo() override {
			Sterling :: getInfo();
			cout << "Enter Eights:\t";
			cin >> eighths;
			while(eighths > 7){
				if(eighths > 7){
					eighths -= 8;
					sterling++;
				}
			}
			cout << endl;
		}
		void displayInfo() override {
			Sterling :: displayInfo();
			cout << "-" << eighths << "/8" << endl;
		}
		void add(Sterfrac a, Sterfrac b){
			eighths = 0;
			cout << "\tEnter First Values to Add:" << endl;
			a.getInfo();
			cout << "\tEnter Second Values to Add:" << endl;
			b.getInfo();
			sterling = a.sterling + b.sterling;
			eighths += a.eighths + b.eighths;
			while(eighths > 7){
				if(eighths > 7){
					eighths -= 8;
					sterling++;
				}
			}
		}
		void subtract(Sterfrac a, Sterfrac b){
			eighths = 0;
			cout << "\tEnter First Values to Add:" << endl;
			a.getInfo();
			cout << "\tEnter Second Values to Add:" << endl;
			b.getInfo();
			sterling = a.sterling - b.sterling;
			eighths += a.eighths - b.eighths;
			while(eighths > 7){
				if(eighths > 7){
					eighths -= 8;
					sterling++;
				}
			}
		}
};

int main(){
	Sterfrac s1, s2, s3, s4;
	cout << "\tEnter and Display:\n";
	s1.getInfo();
	s1.displayInfo();
	cout << endl;
	cout << "\tOperation Testing:\n";
	int choice;
	while(true){
		cout << "Press 1 for Addition" << endl << "Press 2 for Subtraction" << endl << "Press Anything Else to Exit\n";
		cout << "Enter Your Choice: ";
		cin >> choice; 
		switch(choice){
			case 1:
				s4.add(s1, s2);
				s4.displayInfo();
				break;
			case 2:
				s4.subtract(s1, s2);
				s4.displayInfo();
				break;
			default:
				return 0;
				break;
		}
	}
}
