//authentication

#include <iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

int main() {
	string user,pw, User="mlhacks", Pass="TotallyNotRyan";
	int i=0;
	cout << "Please enter your username and password." <<endl;
	cout << "Username: ";
	cin >> user;
	cout << "password: ";
	cin >> pw;
	
	cout <<endl;
	while (user!=User || pw!=Pass ) {
		cout << "INVALID username or password! " <<endl <<endl;
		cout << "Please enter your username and password." <<endl;
		cout << "Username: ";
		cin >> user;
		cout << "password: ";
		cin >> pw;
		i++;
		cout <<endl;
		if (i>=3) {
			cout << "Too many incorrect attempts. Try again later. " <<endl;
			return 0;
		}
	}
	
	cout << "Access granted! Welcome " <<user <<endl;
	
	return 0;
}







