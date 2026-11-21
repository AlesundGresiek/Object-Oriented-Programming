#include<iostream>
#include<iomanip>
using namespace std;

class Time{
	public:
		int hours, minutes, seconds;
		Time(){
			hours = 0;
			minutes = 0;
			seconds = 0;
		}
		virtual void getValues(){
			hours = 100;
			while(hours >= 24 || hours < 0){
				cout << "Enter Hours: ";
				cin >> hours;
				if(hours >= 24 || hours < 0){
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
		}
		Time(int eHours, int eMinutes, int eSeconds){
			hours = eHours;
			minutes = eMinutes;
			seconds = eSeconds;
		}
		virtual void displayTime(){
			cout << setfill('0') << setw(2) << hours << ":";
			cout << setfill('0') << setw(2) << minutes << ":";
			cout << setfill('0') << setw(2) << seconds << endl;
		}
};

class TimeDifference : public Time{
	protected:
		int convHours1, convMinutes1, convHours2, convMinutes2;//workhere
	public:
		void difference(Time a, Time b){
			hours = 0;
			minutes = 0;
			seconds = 0;
			
			convMinutes1 = a.minutes * 60;
			convHours1 = a.hours * 3600;
			a.seconds += convMinutes1;
			a.seconds += convHours1;
			
			convMinutes2 = b.minutes * 60;
			convHours2 = b.hours * 3600;
			b.seconds += convMinutes2;
			b.seconds += convHours2;
			if(a.seconds > b.seconds){
				seconds = a.seconds - b.seconds;
			}
			else{
				seconds = b.seconds - a.seconds;
			}
			
			while (seconds >= 60){
				seconds -= 60;
				minutes++;
				while(minutes >= 60){
					minutes -= 60;
					hours++;
				}
			}
		}
};

class ScheduledTime : protected Time{
	protected:
		string eventDescription;
	public:
		using Time :: Time;
		ScheduledTime(string eEventDescription = "N/A"){
			eventDescription = eEventDescription;
		}
		void getValues() override{
			Time :: getValues();
			cout << "Enter Event Description: ";
			cin >> eventDescription;
		}
		void displayTime() override{
			Time :: displayTime();
			cout << "Event Description:\t" << eventDescription << endl;
		}
};

int main(){
	Time t0;
	Time t1(10, 45, 00);
	Time t2(1, 30, 00);
	TimeDifference t3;
	
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
	cout << endl << "\tT2:\n";
	t2.getValues();
	
	cout << "Difference of T1 and T2: ";
	t3.difference(t1, t2);
	t3.displayTime();
	
	cout << endl << "\tScheduled Time Default Constructor:\n";
	ScheduledTime t4;
	t4.displayTime();
	
	cout << endl << "\tScheduled Time Function Input:\n";
	ScheduledTime t5;
	t5.getValues();
	cout << endl;
	t5.displayTime();
}
