#include<iostream>
using namespace std;

class Circle{
	private:
	double radius, x, y;
	public:
	Circle(){
		radius = 0;
		x = 0;
		y = 0;
	}
	Circle(double eRadius, double eX, double eY){
		radius = eRadius;
		x = eX;
		y = eY;
	}
	void setValues(double eRadius, double eX, double eY){
		radius = eRadius;
		x = eX;
		y = eY;
	}
	void print(){
		cout << "Radius: " << radius << endl;
		cout << "X Coordinate: " << x << endl;
		cout << "Y Coordinate: " << y << endl;
	}
	double area(){
		return (22.0/7.0) * radius * radius;
	}
	double circumference(){
		return (22.0/7.0) * radius * 2;
	}
};

int main(){
	Circle c0();
	double eRadius = -1;
	double eX, eY;
	
	while(eRadius < 0){
		cout << "Enter Radius: ";
		cin >> eRadius;
		if(eRadius < 0){
			cout << "Invalid Value\n";
		}
	}
	
	cout << "Enter X: ";
	cin >> eX;
	cout << "Enter Y: ";
	cin >> eY;
	Circle c1(eRadius, eX, eY);
	c1.print();
	c1.setValues(4, 5, 6);
	c1.print();
	cout << endl;
	cout << "Area: " << c1.area() << endl;
	cout << "Circumference: " << c1.circumference();
}
