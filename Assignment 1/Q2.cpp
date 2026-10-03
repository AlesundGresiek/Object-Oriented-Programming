#include<iostream>
#include<iomanip>
using namespace std;

class Time{
	private:
		int hours, minutes, seconds;
	public:
		Time(){
			hours = 0;
			minutes = 0;
			seconds = 0;
		}
		void getValues(){
			hours = 100;
			while(hours >= 100 || hours < 0){
				cout << "Enter Hours: ";
				cin >> hours;
				if(hours >= 100 || hours < 0){
					cout << "Invalid Value\n";
				}
			}
			
			minutes = 60;
			while(minutes >= 60 || minutes < 0){
				cout << "Enter Minutes: ";
				cin >> minutes;
				if(minutes >= 60 || minutes < 0){
					cout << "Invalid Value\n";
				}
			}
			
			
			seconds = 60;
			while(seconds >= 60 || seconds < 0){
				cout << "Enter Seconds: ";
				cin >> seconds;
				if(seconds >= 60 || seconds < 0){
					cout << "Invalid Value\n";
				}
			}
			cout << endl << endl;
		}
		Time(int eHours, int eMinutes, int eSeconds){
			hours = eHours;
			minutes = eMinutes;
			seconds = eSeconds;
		}
		void displayTime(){
			cout << setfill('0') << setw(2) << hours << ":";
			cout << setfill('0') << setw(2) << minutes << ":";
			cout << setfill('0') << setw(2) << seconds << endl;
		}
		void sum(const Time &a, const Time &b){
			hours = 0;
			minutes = 0;
			seconds = 0;
			seconds = a.seconds + b.seconds;
			while (seconds >= 60){
				seconds -= 60;
				minutes++;
			}
			
			
			minutes += a.minutes + b.minutes;
			while(minutes >= 60){
				minutes -= 60;
				hours++;
			}
			
			hours += a.hours + b.hours;
		}
};

int main(){
	Time t0;
	Time t1(10, 45, 00);
	Time t2(1, 30, 00);
	Time t3;
	
	cout << "No Parameter, initialized at 0 constructor: ";
	t0.displayTime();
	cout << endl;
	
	cout << "Initial Value of T1: ";
	t1.displayTime();
	cout << endl;
	
	cout << "Initial Value of T2: ";
	t2.displayTime();
	cout << endl;
	
	cout << "\tT1:\n";
	t1.getValues();
	cout << "\tT2:\n";
	t2.getValues();
	
	cout << "Sum of T1 and T2: ";
	t3.sum(t1, t2);
	t3.displayTime();
}
