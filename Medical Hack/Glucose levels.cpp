#include <iostream>
#include <iomanip>
#include<windows.h>
#include <fstream>
#include <cmath>

using namespace std;

//printStars function:
void printStars (int n) {
	int i;
	
	for (i=1; i<=n; i=i+1) 
		cout << "*";

}


//Main Function:
int main () {
	//Variables:
	//Index:
	int i;
	
	//Arrays:
	int glucose[500]; //Array to hold the blood sugar level
	float stars[7];	 // Array to store the values of stars for the histogram
	
	//Days:
	int days=0, daysNotmeasured=0;
	float percentOfdays;
	
	//Max:
	int maxbsl=0, dayMax=0;
	
	int n;	//used to check if blood sugar greater than n
	
	//Spikes
	int spike, spikeCount, maxSpike=0, day_maxSpike=0,spikeBSL=0, spike2BSL;
	
	
	cout << "~ Assignment 4 Program Execution: ~" <<endl <<endl;
	
	//opening files:
	ifstream Input;
	Input.open("readings.txt") ;
	if (!Input.is_open()) {
		cout << "Oh no! This file could not be opened..." << endl;
		return 0;
	}
	else {
		cout << "Hooray! File successfully opened :)" << endl;
	}
	
	ofstream Output;
	Output.open("results.txt");
	
	
	//Initialising all locations in the arrays to 0
	for (i=0;i<500;i++) {
		glucose[i] = 0;
	}
	
	for (i=0;i<7;i++) {
		stars[i] = 0;
	}
	
	i = 0; //Resetting i to 0 so it can be reused elsewhere	
	
	Input >> glucose[i];	//input first blood sugar level
	maxbsl = glucose[i];	// initialise max blood sugar level to the first array value
	dayMax = days;			// initialise the day where the blood sugar level was max to 1
	
	while (glucose[i]>=0 && days <=500) {	//Ensures that the number of values in the file is within the size of the arrray
		days++; //counter for the number of readings stored in the file and also the number of days
	
	
		Finding the highest blood sugar level
		if (glucose[i] > maxbsl) {
			maxbsl = glucose[i];
		}

		i++; 	//increment i to be the next location in the array
		Input >> glucose[i];	//store next value into the array	

	} // End of while loop

	Output << "\t~ Results ~" <<endl <<endl;
	

	//Finding the day(s) where the blood sugar level was the highest
	Output << "The highest blood sugar level was: " << maxbsl <<endl;
	Output << "It occurred on:" << endl;
	
	for (i=0;i<days;i++) {
		if (glucose[i] == maxbsl) {		//this checks for ties
			Output << "day " << i+1 << endl;
		}
		
		//Counting the number of days where the BSL was NOT measured
		if (glucose[i]==0) {
			daysNotmeasured++;
		}
			
		
		//Finding the number of spikes and the days the highest spike occurred
		spike = glucose[i]-glucose[i-1];
		if ((spike>=40 || spike <=-40) && i!=0 && glucose[i]!=0 && glucose[i-1]!=0) {   //Counting spikes (increases and decreases) and accounting for errors with i
			spikeCount++;
			if (spike>maxSpike) {
				maxSpike = spike; 
				day_maxSpike = i;
				spikeBSL = glucose[i-1];
				spike2BSL = glucose[i];
			}
		}
		
		
		//Finding vales for the histogram
		if (glucose[i]>=70 && glucose[i]<=79) {
			stars[0]++;
		}
		else {
			if (glucose[i]>=80 && glucose[i]<=89) {
				stars[1]++;
			}
			else {
				if (glucose[i]>=90 && glucose[i]<=99) {
					stars[2]++;
				}
				else {
					if (glucose[i]>=100 && glucose[i]<=109) { //
						stars[3]++;
					}
					else {
						if (glucose[i]>=110 && glucose[i]<=119) {
							stars[4]++;
						}
						else {
							if (glucose[i]>=120 && glucose[i]<=129) { //
								stars[5]++;
							}			
							else {
								if (glucose[i]>=130) {
									stars[6]++;
								}			
							}
						}
					}
				}
			}
		}


	} // End of for loop


	//Check for 3 consecutive days where blood sugar level was above a user input, n	
	cout << endl << "Please enter a blood sugar level: ";
	cin >> n;
	
	Output << endl << "Blood sugar level was higher than " << n << " on these three consecutive days: " <<endl;
	
	for (i=0;i<days;i++) {
		if ((glucose[i-2]>n) && (glucose[i-1] >n) && (glucose[i] >n) ) {
			Output << "Day " << i-1 <<",\t Blood sugar level = " << glucose[i-2] << endl;
			Output << "Day " << i  <<",\t Blood sugar level = " << glucose[i-1] << endl;
			Output << "Day " << i+1 <<",\t Blood sugar level = " << glucose[i] << endl << endl;
		}
	}

	
	//Percentage of days not measured
	percentOfdays = daysNotmeasured*100.0/days;
	
	//Output number of days and percentage of days when the BSL was NOT measured
	Output << "The number of days the blood sugar level was NOT measured = " << daysNotmeasured <<endl;
	Output << fixed << setprecision (1) << "The percentage of days the blood sugar level was NOT measured = " << percentOfdays << "%"<< endl <<endl;
	
	
	//Output number of spikes and the days it occurred:
	Output << "Number of spikes: " << spikeCount << endl;
	Output << "Biggest spike was " << maxSpike << " and ocurred between days " << day_maxSpike << ", with a blood sugar level of " << spikeBSL;
	Output << ", and " << (day_maxSpike+1) << " with a blood sugar level of " << spike2BSL << endl << endl;
	
	
	cout << endl << "Program complete!" << endl;
	cout << "~ Please view 'results.txt' ~ " <<endl <<endl ;

	//Display Histogram:
	cout << "~ Histogram showing readings: ~ "<< endl <<endl;
	cout << "70-79:\t|";
	printStars(ceil(stars[0]/5));
	cout << "\n80-89:\t|";
	printStars(ceil(stars[1]/5));
	cout << "\n90-99:\t|";
	printStars(ceil(stars[2]/5));
	cout << "\n100-109:|";
	printStars(ceil(stars[3]/5));
	cout << "\n110-119:|";
	printStars(ceil(stars[4]/5));
	cout << "\n120-129:|";
	printStars(ceil(stars[5]/5));
	cout << "\n>=130:  |";
	printStars(ceil(stars[6]/5));
	cout << endl << endl;
	
	//Closing files
	Input.close();
	Output.close();
	

	return 0;
} //End of program

