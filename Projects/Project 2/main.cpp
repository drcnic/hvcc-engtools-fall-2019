/*	File: main.cpp
*	Author: Daric Niclas
*	Date: 12/09/19
*	Problem statement:	This program calculates the optimal, lowest-cost conditions to minimize operating costs of a large 
						manufacturing plant with a large number of identical machines that fail randomly at constant rates, 
						and a number of either high quality or low quality technicians to repair them. First, all inputs 
						(failRateMachines[], repRateTechnicians[], technicianWage[], inopMachineCost, maxTechnicians, numMachines)
						are assigned user-entered data. Then, the program loops through all possible combinations of machine types
						/technician types and stores the minimum cost of operation for each combination in optimalSetup[][], along
						with other important information. Finally, the values are displayed in a formatted table.
				
*/

/* Custom compilation parameters */
//#define DEBUG			 
#define NO_DATA_ENTRY	

#include <iostream>
#include <iomanip>
#include <stdlib.h>	// system
#include <stdio.h>	// printf
#include <string>	// std::string, std::to_string

using namespace std;

/* Constants */
#define	ARR_SIZE 80 
const int Good = 0, Poor = 1;

/* Prototypes */
string NumFormat(double, int);
void GetProbMachinesDown(int, int, float, float, float[ARR_SIZE][ARR_SIZE]);
void GetAvgMachinesDown(const int, const int, float[ARR_SIZE][ARR_SIZE], float[]);
void GetAllCosts(const int, const int, float, float, float[], float[]);
float GetMinimum(float[], int, int);
float GetMinimum(float[], int, int, int&);

int main()
{
	float	failRateMachines[2], trafficIntensity, technicianWage[2],
			repRateTechnicians[2], inopMachineCost;

	int		maxTechnicians, numMachines;
	int     techTypes = sizeof(repRateTechnicians) / sizeof(float);
	int		machineTypes = sizeof(failRateMachines) / sizeof(float);

#ifdef NO_DATA_ENTRY	// use hardcoded test values
	numMachines = 70;
	inopMachineCost = 250;
	maxTechnicians = 15;
	failRateMachines[Good] = .033, failRateMachines[Poor] = .038;
	technicianWage[Good] = 17.95, technicianWage[Poor] = 14.00;
	repRateTechnicians[Good] = .40, repRateTechnicians[Poor] = .34;
#ifdef DEBUG
	numMachines = 50;
	maxTechnicians = 5;
	trafficIntensity = .05;
#endif
#else	// data input
	cout << "Number of machines: ";
	cin >> numMachines;
	cout << "Cost of inoperable machine ($/hr): ";
	cin >> inopMachineCost;
	cout << "Maximum number of technicians: ";
	cin >> maxTechnicians;
	cout << "Machine failure rates: Good machines, Poor machines = ";
	cin >> failRateMachines[Good] >> failRateMachines[Poor];
	cout << "Technician hourly wages: Fast techs, Slow techs = ";
	cin >> technicianWage[Good] >> technicianWage[Poor];
	cout << "Technician repair rates: Fast techs, Slow techs = ";
	cin >> repRateTechnicians[Good] >> repRateTechnicians[Poor];

	if (numMachines > ARR_SIZE || maxTechnicians > ARR_SIZE) {	// didn't feel like using vectors, so make sure values don't exceed max array size
		cout << "Error: number of machines or max technicians exceeds max value of: " << ARR_SIZE << ". Aborting..." << endl;
		cin.get();
		return 1;
	}

	// check for incorrect negative inputs
	if (numMachines < 0 || inopMachineCost < 0 || maxTechnicians < 0 || failRateMachines[Good] < 0 || failRateMachines[Poor] < 0
		|| technicianWage[Good] < 0 || technicianWage[Poor] || repRateTechnicians[Good] < 0 || repRateTechnicians[Poor]) {
		cout << "Error: negative value given as input. Aborting..." << endl;
		cin.get();
		return 2;
	}
#endif

	system("cls");	// clear console

	/* output user-input values in a nice table */
	cout << "Number of machines: " << numMachines << endl;
	cout << "Cost of inoperable machine: $" << inopMachineCost << "/hr" << endl;
	cout << "Maximum number of technicians: " << maxTechnicians << endl;
	cout << "Failure rates: " << left << "Good = " << setw(10) << failRateMachines[Good] << "Poor = " << setw(10) << failRateMachines[Poor] << endl;
	cout << "Hourly rates:  " << left << "Fast = " << setw(10) << technicianWage[Good] << "Slow = " << setw(10) << technicianWage[Poor] << endl;
	cout << "Repair rates:  " << left << "Fast = " << setw(10) << repRateTechnicians[Good] << "Slow = " << setw(10) << repRateTechnicians[Poor] << endl;
	cout << endl << endl;

	cout << "Press return to continue...";
	cin.get();

	system("cls");	// clear console
	// first half
	cout << setprecision(2) << fixed << setfill(' ');
	cout << "BASIC PARAMETERS:" << endl;
	cout << "Downtime loss per machine = $" << inopMachineCost << "/hr" << endl;
	cout << "Total number of machines = " << numMachines << endl;
	cout << left << setw(30) << "Types of technicians: " << setw(15) << "Fast" << setw(15) << "Slow" << endl;
	cout << left << setw(30) << "      Corresponding wages" << setw(15) << "$" + NumFormat(technicianWage[Good], 4) + "/hr" << setw(15) << "$" + NumFormat(technicianWage[Poor], 4) + "/hr" << endl;
	cout << setprecision(3);
	cout << left << setw(30) << "      And repair rates" << setw(15) << NumFormat(repRateTechnicians[Good], 4) + "/hr" << setw(15) << NumFormat(repRateTechnicians[Poor], 4) + "/hr" << endl << endl;
	cout << left << setw(30) << "Types of machines: " << setw(15) << "Good" << setw(15) << "Poor" << endl;
	cout << left << setw(30) << "      Failure rates" << setw(15) << NumFormat(failRateMachines[Good], 4) + "/hr" << setw(15) << NumFormat(failRateMachines[Poor], 4) + "/hr" << endl << endl << endl << endl;

	// second half
	cout << left << setw(15) << "Type of" << setw(15) << "Type of" << setw(20) << "Traffic" << setw(15) << "Optimum" << setw(15) << "Total" << endl;
	cout << left << setw(15) << "worker" << setw(15) << "machine" << setw(20) << "intensity" << setw(15) << "number" << setw(15) << "Cost" << endl;
	cout << setfill('-') << setw(15 * 4 + 20) << '-' << endl << setfill(' ');

	float optimalSetup[4][3];	// [individual cases][case specs]; for individual cases index, ft & gd = 0, ft & pr = 1, etc
								// CASE X: [x][0]: trafficIntensity		[x][1]: optimum technicians for lowest cost 	[x][2]: lowest cost
	float probMachineDown[ARR_SIZE][ARR_SIZE], avgMachinesDown[ARR_SIZE], cost[ARR_SIZE];

	for (int techType = 0; techType < techTypes; techType++) {	// 4 cases (conditions): f & g, f & p, s & g, s & p
		static int iteration = 0;	// track each time a loop completes
		for (int machineType = 0; machineType < machineTypes; machineType++) {
			trafficIntensity = failRateMachines[machineType] / repRateTechnicians[techType];

			GetProbMachinesDown(maxTechnicians, numMachines, inopMachineCost, trafficIntensity, probMachineDown);
			GetAvgMachinesDown(maxTechnicians, numMachines, probMachineDown, avgMachinesDown);
			GetAllCosts(maxTechnicians, numMachines, inopMachineCost, technicianWage[techType], avgMachinesDown, cost);
			
			int index;
			float min = GetMinimum(cost, 1, maxTechnicians, index);	// find minimum in costs and get its index

			optimalSetup[iteration][0] = trafficIntensity;
			optimalSetup[iteration][1] = index;
			optimalSetup[iteration][2] = min;

			iteration++;
			//cin.get();
		}
	}

	cout << left << setw(15) << "Fast" << setw(15) << "Good" << setw(20) << setprecision(3) << optimalSetup[0][0] << setw(15) << setprecision(0) << optimalSetup[0][1] << setw(15) << "$" + NumFormat(optimalSetup[0][2], 6) << endl;
	cout << left << setw(15) << "Fast" << setw(15) << "Poor" << setw(20) << setprecision(3) << optimalSetup[1][0] << setw(15) << setprecision(0) << optimalSetup[1][1] << setw(15) << "$" + NumFormat(optimalSetup[1][2], 6) << endl;
	cout << left << setw(15) << "Slow" << setw(15) << "Good" << setw(20) << setprecision(3) << optimalSetup[2][0] << setw(15) << setprecision(0) << optimalSetup[2][1] << setw(15) << "$" + NumFormat(optimalSetup[2][2], 6) << endl;
	cout << left << setw(15) << "Slow" << setw(15) << "Poor" << setw(20) << setprecision(3) << optimalSetup[3][0] << setw(15) << setprecision(0) << optimalSetup[3][1] << setw(15) << "$" + NumFormat(optimalSetup[3][2], 6) << endl;

	return 0;	// end
}

// Converts numeric input to a string of length len
string NumFormat(double input, int len)
{
	return to_string(input).substr(0, len + 1);
}

//
void GetProbMachinesDown(int maxTechnicians, int numMachines, float inopMachineCost, float trafficIntensity, float probMachineDown[ARR_SIZE][ARR_SIZE])
{
	for (int i = 0; i < ARR_SIZE; i++) {
		probMachineDown[i][0] = 1;	// initialize P(0)'s to 1 for all possible values of technician
		probMachineDown[0][i] = -1;	// can't have zero technicians; initialized to -1 so errors are easier to diagnose
	}

	for (int technicians = 0; technicians <= maxTechnicians; technicians++) {
		for (int machinesDown = 0; machinesDown < numMachines; machinesDown++) {
			if (machinesDown < technicians)
				probMachineDown[technicians][machinesDown + 1] = trafficIntensity * ((numMachines - machinesDown) / (machinesDown + 1.0)) * probMachineDown[technicians][machinesDown];
			else if (technicians <= machinesDown && machinesDown <= numMachines)
				probMachineDown[technicians][machinesDown + 1] = trafficIntensity * ((numMachines - machinesDown) / (float(technicians))) * probMachineDown[technicians][machinesDown];
			else {	// abort if a variable is out of bounds
				printf("Error: unable to calculate probMachineDown[%d][%d]", technicians, machinesDown + 1);
				cout << " Aborting...\n";
				cin.get();
				return;
			}

			//printf("Prob %d machines down with %d technicians: %f\n", machinesDown, technicians, probMachineDown[technicians][machinesDown]);
		}
	}
}

//
void GetAvgMachinesDown(const int maxTechnicians, const int numMachines, float probMachineDown[ARR_SIZE][ARR_SIZE], float avgMachinesDown[])
{	
	for (int technicians = 1; technicians <= maxTechnicians + 1; technicians++) {
		// start at 1 since P(0) equals 1 for all numbers of technicians
		float sumProbabilities = 1;		// sum of probabilities from P(0) to P(N)
		float prodProbabilities = 1;	// sum of n*P(n) from P(0) to P(N)

		for (int machinesDown = 0; machinesDown < numMachines; machinesDown++) {
			sumProbabilities += probMachineDown[technicians][machinesDown + 1];	// accumulate sum of all P(n) to P(N)
			prodProbabilities += probMachineDown[technicians][machinesDown + 1] * (machinesDown + 1);	// accumulate all values of n*P(n) to N*P(N)
		}

		avgMachinesDown[technicians] = (prodProbabilities / sumProbabilities);	// average machines down for [technicians] technicians 
		//printf("Average machines down for max of %d techs: %f\n", technicians, avgMachinesDown[technicians]);
	}
}

// 
void GetAllCosts(const int maxTechnicians, const int numMachines, float inopMachineCost, float techTypeWage, float avgMachinesDown[], float cost[])
{
	for (int technicians = 1; technicians <= maxTechnicians; technicians++) {
		cost[technicians] = technicians * techTypeWage + (avgMachinesDown[technicians] * inopMachineCost);	// estimated total cost of operation with [technicians] technicians
		//cout << "R = " << technicians << ": " << cost[technicians] << endl;
	}
}

// Finds and returns minimum value given a list, a starting index, and the size of desired search region
float GetMinimum(float arr[], int start, int size)
{
	float min = arr[start];
	int end = size - start;

	for (int i = start; i < end; i++) {
		if (arr[i] < min)
			min = arr[i];
	}

	return min;	// return min cost
}

// Finds and returns minimum value given a list, a starting index, and the size of desired search region; additionally passes integer value by reference 
float GetMinimum(float arr[], int start, int size, int& index)
{
	float min = arr[start];
	int end = size - start;
	int indx = NULL;

	for (int i = start; i < end; i++) {
		if (arr[i] < min) {
			min = arr[i];
			indx = i;
		}
	}

	index = indx;	// pass index of min cost by reference
	return min;		// return min cost
}
