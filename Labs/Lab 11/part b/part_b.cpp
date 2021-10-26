/*	File: part_b.cpp
 *	Author: Daric Niclas
 *	Date: 11/19/19
 *	Purpose:
 */

#define ARR_SIZE 10
#include <iostream>

int main()
{
	using namespace std;
	int score[ARR_SIZE] = { -1 };
	float scoreSum = 0;

	for (int i = 0; i < ARR_SIZE; i++) {	// input loop
		cout << "Enter score " << i + 1 << ": ";
		cin  >> score[i];		// get score, store @ index i
		scoreSum += score[i];	// accumulate sum for mean calc.
	}

	cout << "\n\n\nRESULTS:\n\n";

	int max = score[0], min = score[0];	// holders for min/max

	for (int i = 0; i < ARR_SIZE; i++) {	// output loop
		cout << "Score " << i + 1 << ": " << score[i] << endl;

		if (score[i] > max)	// test for the max
			max = score[i];

		if (score[i] < min)	// test for the min
			min = score[i];
	}

	// output
	cout << "Average: " << scoreSum / (float)ARR_SIZE << endl;
	cout << "Minimum: " << min << endl;
	cout << "Maximum: " << max << endl;

	return 0;
}