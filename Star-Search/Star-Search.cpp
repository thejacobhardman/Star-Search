// Jacob Hardman
// Comp Sci 1
// Professor Jennifer Bailey
// 11/2/19

#include <iostream>
#include <string>

using namespace std;

void main()
{
	bool isRunning = true;
	string userInput;

	
	while (isRunning) {

		double scores[5] = {0, 0, 0, 0, 0};
		
		for (int i = 0; i < 5; i++) {
			getJudgeData(scores[i]);
		}



		for (int i = 0; i < 5; i++) {
			calcScore(scores[i]);
		}

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

void getJudgeData(double& score) {
	do {
		cout << "Enter a judge's score: ";
		cin >> score;
	} while (score > 10 && score < 0);
}

void calcScore(double& score) {
	cout << "Blah";
}

int findLowest() {
	return 0;
}

int findHighest() {
	return 0;
}
