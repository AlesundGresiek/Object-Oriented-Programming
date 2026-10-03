#include<iostream>
#include<windows.h>
using namespace std;

class Angle{
	private:
		int degrees;
		float minutes;
		char direction;
	public:
		Angle(){
			degrees = 0;
			minutes = 0.0;
			direction = 'N';
		}
		Angle(int eDegrees, float eMinutes, char eDirection){
			degrees = eDegrees;
			minutes = eMinutes;
			direction = eDirection;
		}
		void getValues(){
			cout << "Enter Degrees: ";
			cin >> degrees;
			while(degrees >= 360){
				degrees -= 360;
			}
			
			minutes = 60;
			while(minutes >= 60){
				cout << "Enter Minutes: ";
				cin >> minutes;
				if(minutes >= 60){
					cout << "Invalid Input. Try Again:\n";
				}
			}
			
			direction = 'f';
			while(direction != 'n' && direction != 'e' && direction != 'w' && direction != 's' && direction != 'N' && direction != 'E' && direction != 'W' && direction && 'S'){
				cout << "Enter Direction: ";
				cin >> direction;
				if(direction != 'n' && direction != 'e' && direction != 'w' && direction != 's' && direction != 'N' && direction != 'E' && direction != 'W' && direction && 'S'){
					cout << "Invalid Input. Try Again:\n";
				}
			}
		}
		void displayAngle(){
			char directionUpper = toupper(direction);
			SetConsoleOutputCP(CP_UTF8);
			cout << degrees << "\u00B0" << minutes << "'" << directionUpper << endl;
		}
};

int main(){
	cout << "Default Constructor:\n";
	Angle null;
	null.displayAngle();
	
	cout << "Parameterized Constructor:\n";
	Angle paraCon(149, 34.8, 'N');
	paraCon.displayAngle();
	
	cout << "Input from User:\n";
	Angle user;
	user.getValues();
	cout << "Angle: ";
	user.displayAngle(); 
}
