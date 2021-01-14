//encryption

//Libraries used:
#include <iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

#define QUIT 9	

int Menu() {
	int num=0;
	bool validChoice;
	validChoice = false;
	
	while (!validChoice) {
		system("cls");
		cout << "1. Encryption" << endl;
		cout << "2. Decryption" <<endl;
		cout << "Press 9 to Quit" <<endl;
		cin >> num;
	
		if (num>=1 && num<=QUIT)	// Ensures choice is within the range of menu options
			validChoice = true;
		else {
			cout << "Invalid selection. Try again." <<endl;
		}
		system("cls");
	}
	return num;
}


//Main Function:
int main () {
	//Var
	int num=0,i=0, location=0;
	string text;
	string Text[5];
	string Ciph[5]={"A%dsn2#ty1$","ES785#@123$","99983%$dg","B%dss2**23","qwrt@smn43*"};
	
	for (i=0;i<5;i++) {
		Text[i] = " ";
	}
	
	while (num!=9) {
		num=Menu();
		
		if (num==1) {
			cout << "Please enter the text you would like to encrypt: (Words cannot have spaces) " <<endl;
			cin >> text;
			for (i=0;i<5;i++) {
				if (Text[i]==" ") {
					Text[i]=text;
					location=i;
					break;
				}
				else {
					cout << "ENCRYPTING..." <<endl;
					Sleep(110);
				}
			}
			cout << "Encrypted message: " << Ciph[location] <<endl;
			system("pause");
		}
		
		else {
			if (num==2) {
				cout << "Please enter the text you would like to decrypt: " <<endl;	
				cin >> text;
				for (i=0;i<5;i++) {
					if (text==Ciph[i]) {
						location=i;
						break;
					}
					else {
						cout << "DECRYPTING..." <<endl;
						Sleep(100);
					}
				}
				cout <<"Decrypted message: ";
				cout << Text[location]<<endl;
				system("pause");
			}
		}
	}
	return 0;
} //End of program










