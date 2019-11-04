// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 11/2/19

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void getJudgeData(double& score) {
	bool goodInput = false;
	while (goodInput == false) {
		cout << "Enter a judge's score: ";
		cin >> score;
		if (score > 10 || score < 0) {
			cout << "Please enter a valid number between 0 and 10." << endl;
		}
		else {
			goodInput = true;
		}
	}
}

int findLowest(int lowestNum, double scores[]) {

	for (int i = 0; i < 5; i++) {
		if (scores[i] < scores[i + 1] && scores[i] < lowestNum) {
			lowestNum = i;
		}
	}

	return lowestNum;
}

int findHighest(int highestNum, double scores[]) {

	for (int i = 0; i < 5; i++) {
		if (scores[i] > scores[i + 1] && scores[i] > highestNum) {
			highestNum = i;
		}
	}

	return highestNum;
}

void calcScore(double& finalScore, double newScores[]) {
	double sum = 0.0;
	for (int i = 0; i < 3; i++) {
		sum += newScores[i];
	}

	finalScore = (sum / 3.0);
}

void main()
{
	bool isRunning = true;
	string userInput;
	
	while (isRunning) {

		double scores[5], finalScore = 0.0;
		int highestNum = 0, lowestNum = 10;
		
		for (int i = 0; i < 5; i++) {
			getJudgeData(scores[i]);
		}

		lowestNum = findLowest(lowestNum, scores);
		highestNum = findHighest(highestNum, scores);

		vector<double> dynamicScores = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < 5; i++) {
			dynamicScores[i] = scores[i];
		}

		dynamicScores.erase(dynamicScores.begin() + lowestNum);
		dynamicScores.erase(dynamicScores.begin() + highestNum - 1);

		dynamicScores.resize(3);

		double newScores[3];
		copy(dynamicScores.begin(), dynamicScores.end(), newScores);

		calcScore(finalScore, newScores);

		cout << setprecision(1) << "After dropping the highest and lowest scores, the average score was: " << finalScore << endl;

		bool userConfirm = false;
		while (userConfirm == false) {
			cout << "Would you like to run the program again? (Y/N): ";
			cin >> userInput;

			if (userInput == "Y" || userInput == "y") {
				userConfirm = true;
			}
			else if (userInput == "N" || userInput == "n") {
				userConfirm = true;
				isRunning = false;
			}
			else {
				cout << "Please enter a valid selection." << endl;
			}
		}
	}
}
