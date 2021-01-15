#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>

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
	//Variables
	string URL;
	int Sday=0, Smonth=0, Syear=0, day=0, month=0, year=0, Eday=0, Emonth=0,Eyear=0;
	int numOfdays = 0;
	int views = 1;
	int likes=0,dislikes=0;
	int maxViews=0, max2Views=0, dayMostviewed=0, day2Mostviewed=0;
	int totalViews=0, totalLikes=0, totalDislikes=0;
	float avgViews=0, avgLikes=0,avgDislikes=0;
	char response;
	
	
	ifstream inputFile;
	inputFile.open("Views.txt") ;
	if (!inputFile.is_open()) {
		cout << "ERROR! File could not be opened..." << endl;
		return 0;
	}
	else {
		cout << "File successfully opened :)" << endl << endl;
	}
	
	ofstream VideoStats, Greater5k, Likeslessdislikes;
	VideoStats.open("VideoStats.txt");
	Greater5k.open("Views_Greater_5000.txt");
	Likeslessdislikes.open("Likes_LessThanDislikes.txt");
	
	
	inputFile >> URL;
	inputFile >> day >> month >> year;
	Sday = day;
	Smonth = month;
	Syear = year;
	
	
	inputFile >> views;
	
	while (views>0) {
		numOfdays = numOfdays + 1;
		
		//Updating the number of views, likes and dislikes
		inputFile >> likes;
		inputFile>> dislikes;
		
		Eday = day;
		Emonth = month;
		Eyear = year;
		
		totalViews = totalViews + views;
		totalLikes = totalLikes + likes;
		totalDislikes = totalDislikes + dislikes;
		
		//changing the dates algorithm
		if (month==4 || month ==6 || month==9|| month==11) {
			if (day>=30) {
				month=month+1;
				day = 0;
			}
		}
		
		else {
			if(month==2) {
				if (year%4==0) {
					if (day>=29) {
						month = month+1;
						day = 1;
					}
				}
			}
			else {
				if (month==12 && day>31) {
					month =1;
					day = 1;
					year = year +1;
				}
				else {
					if (day>=31) {
						month = month + 1;
						day = 0;
					}
				}
			}
		}
		

		if (likes<dislikes) {
			Likeslessdislikes << "On " << day << "/" << month << "/" << year << ":" <<endl;
			Likeslessdislikes << "Number of likes: " << likes << endl;
			Likeslessdislikes << "Number of dislikes: " << dislikes << endl << endl; 
		}
		
		
		if (views<maxViews && (views >max2Views)) {
			max2Views = views;
			day2Mostviewed = dayMostviewed;	
			dayMostviewed = numOfdays;
			
		}
		else {
			if  (views>maxViews) {
				max2Views=maxViews;
				maxViews = views;
				day2Mostviewed = dayMostviewed;
				dayMostviewed = numOfdays;
			}
		}

		
		
		//Finding the date when views > 5000
		if (views > 5000) {
			Greater5k << "On " << day << "/" << month << "/" << year << ":" << endl;
			Greater5k << "Number of views: " << views << endl << endl;
		}
	
		inputFile >> views;
		day = day + 1;
		
	}
	
		
	avgViews = totalViews *1.0 /numOfdays;
	avgLikes = totalLikes *1.0 /numOfdays;
	avgDislikes = totalDislikes *1.0 /numOfdays;
	
	
	// Output --> VideoStats.txt
	VideoStats << "- Video Statistics -" << endl;
	VideoStats << "Starting date: " << Sday << "/" << Smonth << "/" << Syear << endl;
	VideoStats << "Ending date: " << Eday << "/" << Emonth << "/" << Eyear << endl << endl;
	
	
	//Output the total number of days processed
	VideoStats << "Number of days processed: " << numOfdays << endl << endl;
	
	
	//Output the total number of views, likes and dislikes
	VideoStats << "The total number of views: " << totalViews << endl;
	VideoStats << "The total number of likes: " << totalLikes << endl;
	VideoStats << "The total number of dislikes: " << totalDislikes << endl << endl;
	
	
    //Output the average the number of views, likes and dislikes
	VideoStats << "The average number of views: " << avgViews << endl;
	VideoStats << "The average number of likes: " << avgLikes << endl;
	VideoStats << "The average number of dislikes: " << avgDislikes << endl <<endl;
	
	
	//Output the days with the highest and second highest amount of views
	VideoStats << "The day with the highest number of views = " << dayMostviewed << " with " << maxViews << " views." << endl;
	VideoStats << "The day with the second highest number of views = " << day2Mostviewed << " with " << max2Views << " views." << endl;
	
	cout << "Results output to files" <<endl;
	//Viewing the video:
	cout << "Do you want to view the original video?\nEnter y or n." << endl;
	cin >> response;
	if (response=='y') {
		showVideo(URL);	
	}
	

	//Closing files and program termination
	inputFile.close();
	VideoStats.close();
	Greater5k.close();
	Likeslessdislikes.close();
    cout << endl << "~ Program successfully completed ~" << endl;
	cout << "Terminating...\nGoodbye." << endl;
	
	return 0;
} 
