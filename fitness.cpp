//fitness

#include <iostream>
#include <conio.h>
#include<windows.h>
#include <iomanip>

using namespace std;

int main() {
	string user,pw, User="mlhacks", Pass="TotallyNotRyan";
	int age, i=0, calories;
	float height, weight, BMI;
	char gender;
	
	
	cout << "Fitness Analysis: " <<endl;
	cout << "Are you male or female? (Enter: M=male,  F= female,O=other)" <<endl;
	cin >> gender;
	
	cout << "Enter your age: ";
	cin >> age;
	
	cout << "Enter your weight in kg: ";
	cin >> weight;
	
	cout << "Enter your height in m: ";
	cin >> height;
	
	cout << endl;
	BMI =weight/(height*height);
	cout <<fixed << setprecision(2) << "Your BMI is " << BMI <<endl;
	
	if (BMI >=25.0) {
		cout << "You are in the overweight range " <<endl;
	}
	else {
		if (BMI>=18.5 && BMI <= 24.9){
			cout << "You are in the healthy range" <<endl;
		}
		else {
			if (BMI==0) {
				cout << "ERROR IN CALCULATIONS. INFO ENTERED INCORRECTLY." <<endl;
			}
			else {
			cout << "You are underweight." <<endl;
			}
		}
	}
	cout << "Please remember to get enough exercise and to drink 8 cups of water a day" <<endl;
	
	return 0;
}




