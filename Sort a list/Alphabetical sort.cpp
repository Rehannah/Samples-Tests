#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;


int main () {
	//Var
	string Words[100];
	int i,num, numOfwords;
	string holder = " ";
	
	ifstream in;
	in.open ("words.txt");
	
	cout << "Press 1 if you want to enter a list of words to be sorted (max = 100 words)" << endl;
	cout << "Press 2 if you want to use the words list ('words.txt')" <<endl;
	cin >> num;
	
	while (num!=1 && num!=2) {
		cout << "ERROR! Number entered out of range! Try again" <<endl;
		cout << "Press 1 if you want to enter a list of words to be sorted (max = 100 words)" << endl;
		cout << "Press 2 if you want to use the words list ('words.txt')" <<endl;
		cin >> num;
	}
	
	if (num==1) {
		string words=" ";
		i=0;
		cout << "Please enter the words you would like to sort and enter 0 when you are done. (100 max words can be stored)" <<endl;
		cin >> words;
		while (words!="0") {
			Words[i]=words;
			i++;
			cin >>words;
		}
		cout <<endl;
	}
	
	else {
		if (num==2) {
			if (!in.is_open()) {
			cout << "ERROR 404! Words list not found..." << endl;
			return 404;
			}
			else {
			cout << "Words list successfully retrieved." << endl <<endl;
			while (!in.eof()) {
				in >> Words[i];
				i++;
			}		
			}
		}
	}
	
	numOfwords=i;
	cout << endl << "Unsorted words list:" <<endl;
	for (i=0;i<numOfwords;i++) {
		cout << Words[i] <<endl;
	}	
	
	//Sort list
	for (i=0;i<numOfwords;i++) {
		for (int x=i+1; x < numOfwords; x++) {
			if (Words[i] > Words[x]) {
				holder=Words[i];
				Words[i]=Words[x];
				Words[x]=holder;
			}
		}
	}
	
	cout << endl << "Alphabetically sorted list:" <<endl;
	for (i=0;i<numOfwords;i++) {
		cout << Words[i] << endl;
	}
	
	in.close();
	return 0;
}


