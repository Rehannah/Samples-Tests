//RNG
#include <iostream>
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
using namespace std;

int RNG(int seed) {
	int x;
	int Numbers[10];
	for (int i=1;i<=10;i++) {
		Numbers[i-1]=i;
	}
		x = (seed % 10);
		if (seed%20 > 15) {
			seed = seed +10;
			x =(43+x + seed)%10;
		}
	cout << Numbers[x] << endl;
}

int main () {
	//Var
	char key = ' ';

	while (key!='b') {
		cout << "Press 'a' to generate a random number between 1 and 10 or 'b' to terminate program: ";
		cin >> key;
		if (key=='a') {
			(RNG(time(NULL)) % 9) + 1;
		}
			else {
			cout << "Please press a. I can't do anything else." <<endl;
			}
		}
 	return 0;
}


