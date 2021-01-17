//music lyrics
#include <iostream>
#include <cstring>
#include <conio.h>
#include<windows.h>

using namespace std;

//showVideo function
void showVideo (string URL) {
	char cURL [50];
	int i;

	for (i = 0; i < URL.length(); i=i+1){
    	cURL[i] = URL[i];
	}

	cURL[URL.length()] = '\0';
    
    ShellExecute(NULL, "open", cURL, NULL, NULL, SW_SHOWNORMAL);
}

int main() {
	string Lyrics[15]={"5, 4, 3, 2, 1.", "We're going on a trip", "in our favorite rocket ship", "Zooming through the sky, Little Einsteins.",
	"Climb aboard, get ready to explore", "There's so much to find, Little Einsteins", "We're going on a mission, start the countdown",
	"5, 4, 3, 2, 1", "Everyone to rocket, rev it up now RRRRRRRRRRRRRRR", "Come on, let's go, Little Einsteins", "We need you, Little Einsteins",
	"Yeah!"};
	string response;
	
	cout << "Are you ready to listen to the song? Enter yes or no." <<endl;
	cin >> response;
	
	if (response == "yes") {
		showVideo("https://www.youtube.com/watch?v=7eL1Bfv8Y9k");
		cout << "Displaying lyrics..." <<endl;
		Sleep(2500);
		system("CLS");
		
		for (int i=0;i<=8;i++) {
			cout << Lyrics[i] <<endl;
			Sleep(2500);
		}
		system("CLS");
		for (int i=1;i<=5;i++) {
			cout << Lyrics[i] <<endl;
			Sleep(2500);
		}
		system("CLS");
		for (int i=9;i<=11;i++) {
			cout << Lyrics[i] <<endl;
			Sleep(2500);
		}
		system("CLS");
		cout << "END OF SONG" <<endl;
	}
	else
	return 0;
} 
