//Data Visualisation
//Libraries used & standard namespace
#include <iostream>
#include <fstream>
using namespace std;

//Defining printStars Function:
void printStars (int n) {
	int i;
	for (i=1; i<=n; i=i+1) 
		cout << "*";
}

//Main Function:
int main () {
	//Variables:
	int x; //counter for the for loop
	
	//Variables for reference country:
	string Countries[25];
	int Population[25];
	int NumofCases[25];
	int NumofDeaths[25];
	int NumofTests[25];
	
	string ref_country;
	int ref_population, ref_numOfcases, ref_numOfdeaths, ref_numOftests;
	float ref_casesPmill, ref_deathsPmill, ref_testsPmill, ref_percentOfdeaths;
	
	//Variables for other country:
	string country_name;
	int population, numOfcases, numOfdeaths, numOftests;
	float casesPmill, deathsPmill, testsPmill, percentOfdeaths;
	
	//Variables for comparisons:
	int numOfcountries, diff_casesPmill, diff_deathsPmill, diff_testsPmill, max_casesPmill, min_deathsPmill; 
	string country_max, country_min;
	
	ifstream in;
	in.open("Covid data.txt") ;
	for (int i=0;i<25;i++) {
		in >> Countries[i] >> Population[i] >> NumofCases[i] >> NumofDeaths[i] >> NumofTests[i];
	}
	//Prompt user for inputs:
	cout << "\t    COVID-19 ANALYSIS:" << endl;
	cout << endl;
	cout << "*NOTE: Please use underscores instead of spaces in the country name*\n eg: New Zealand is entered as New_Zealand." << endl;
	cout << endl;
	cout << "What is the name of the reference country? ";
	cin  >> ref_country;
	for (int i=0;i<25;i++) {
		if (ref_country==Countries[i]) {
			ref_population = Population[i];
			ref_numOfcases = NumofCases[i];
			ref_numOfdeaths = NumofDeaths[i];
			ref_numOftests = NumofTests[i];
		}
	}
	
	cout << endl;
	
	cout << "How many countries will be compared to " << ref_country << "? ";
	cin  >> numOfcountries;
	cout << endl;
	
	//For loop which prompts for inputs for the other country and then compares it to the reference country:
	for (x=1; x<=numOfcountries; x=x+1){
		cout << "Please enter the following information for country number " << x << ":" << endl;
		cout << "What is the name of the next country? ";
		cin  >> country_name;
		
		for (int i=0;i<25;i++) {
		if (country_name==Countries[i]) {
			population = Population[i];
			numOfcases = NumofCases[i];
			numOfdeaths = NumofDeaths[i];
			numOftests = NumofTests[i];
		}
	}
		cout << endl << endl;
		
		
		//Calculations: (use of 1000000.0 to facilitate integer division)
		//Calculations related to reference country:
		ref_casesPmill  = ref_numOfcases * 1000000.0 / ref_population;
		ref_deathsPmill = ref_numOfdeaths * 1000000.0 / ref_population;
		ref_testsPmill  = ref_numOftests * 1000000.0 / ref_population;
		ref_percentOfdeaths = ref_deathsPmill * 100.0 / 1000000.0;
		
		///Calculations related to the other country:
		casesPmill  = numOfcases * 1000000.0 / population;
		deathsPmill = numOfdeaths * 1000000.0 / population;
		testsPmill  = numOftests * 1000000.0 / population;
		percentOfdeaths = deathsPmill * 100.0 / 1000000.0;
		
		//Comparisons:
		//Compares how much more cases are in either country and the difference between them
		if (ref_casesPmill >= casesPmill)
			diff_casesPmill = ref_casesPmill - casesPmill;
		else {
			if (ref_casesPmill < casesPmill)
				diff_casesPmill = casesPmill - ref_casesPmill;
		}
		
		//Compares how much more deaths are in either country and the difference between them
		if (ref_deathsPmill >= deathsPmill)
			diff_deathsPmill = ref_deathsPmill - deathsPmill;
		else {
			if (ref_deathsPmill < deathsPmill)
				diff_deathsPmill = deathsPmill - ref_deathsPmill;
		}
		
		//Compares how much more tests are in either country and the difference between them
		if (ref_testsPmill >= testsPmill)
			diff_testsPmill = ref_testsPmill - testsPmill;
		else {
			if (ref_testsPmill < testsPmill)
				diff_testsPmill = testsPmill - ref_testsPmill;
		}
		
		//Finding the country with the highest number of cases per million:
		if (ref_casesPmill > casesPmill && ref_casesPmill > max_casesPmill) {
			max_casesPmill = ref_casesPmill;
			country_max = ref_country;
		}
		else {
			if (casesPmill > ref_casesPmill && casesPmill > max_casesPmill) {
				max_casesPmill = casesPmill;
				country_max = country_name;
			}
		}
		
		//Finding the country with the lowest number of deaths per million:
		if (deathsPmill < ref_deathsPmill && deathsPmill < min_deathsPmill) {
			min_deathsPmill = deathsPmill;
			country_min = country_name;
		}
		else {
			if (ref_deathsPmill < deathsPmill && ref_deathsPmill < min_deathsPmill) {
				min_deathsPmill = ref_deathsPmill;
				country_min = ref_country;
			}
		}
		
		
		//Outputs:
		//Comparison between reference country and another country:
		cout << "\tData Visualisation:" <<endl;
		cout << "\tComparison between "  << ref_country << " and " << country_name << ": " << endl;
		cout << "===========================================================" << endl;
		cout << endl;
		cout << "Name of country: \t" << ref_country << "  vs.  " << country_name << endl;
		cout << "Size of population: \t" << ref_population << "  vs.  " << population << endl;
		cout << "Cases per million: \t" << ref_casesPmill << "  vs.  " << casesPmill << "    (" << diff_casesPmill << " less)" << endl;
		cout << "Deaths per million: \t" << ref_deathsPmill << "  vs.  " << deathsPmill << "    (" << diff_deathsPmill << " less)" << endl;
		cout << "Graph:            \t";
		printStars (ref_deathsPmill/50);
		cout << "  :  ";
		printStars(deathsPmill/50);
		cout << endl;
		cout << "Percentage of deaths: \t" << ref_percentOfdeaths << "%  vs.  " << percentOfdeaths << "%" << endl;
		cout << "Tests per million: \t" << ref_testsPmill << "  vs.  " << testsPmill << "    (" << diff_testsPmill << " less)" << endl;
		cout << endl;
		cout << "===========================================================" << endl << endl;
	}
	
	cout << country_max << " has the most cases per million with " << max_casesPmill << " cases per million." << endl;
	cout << country_min << " has the least number of deaths per million with " << min_deathsPmill << " deaths per million." << endl << endl;
	cout << "\t    ~ END OF COVID-19 ANALYSIS ~" << endl;
	return 0;
}

