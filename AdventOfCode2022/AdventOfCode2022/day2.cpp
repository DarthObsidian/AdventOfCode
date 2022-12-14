#include "day2.h"

using std::ifstream;
using std::string;
using std::cout;

int do_day_two() {
	ifstream file;
	file.open("./dayTwoInput.txt");
	if (file.is_open()) {
		string line;
		int score = 0;
		while (getline(file, line)) {
			char opponent = line[0];
			char player = line[2];
			if ((opponent == 'A' && player == 'X')
				|| (opponent == 'B' && player == 'Y')
				|| (opponent == 'C' && player == 'Z')) {
				score += 3;
			}
			else if ((opponent == 'A' && player == 'Y')
				|| (opponent == 'B' && player == 'Z')
				|| (opponent) == 'C' && player == 'X') {
				score += 6;
			}

			if (player == 'X') {
				score += 1;
			}
			else if (player == 'Y') {
				score += 2;
			}
			else if (player == 'Z') {
				score += 3;
			}
		}
		cout << score << '\n';
		file.close();
	}
	return 0;
}

int day_two_part_two() {
	ifstream file;
	file.open("./dayTwoInput.txt");
	if (file.is_open()) {
		string line;
		int score = 0;
		while (getline(file, line)) {
			char opponent = line[0];
			char player = line[2];
			score += get_correct_value(opponent, player);
		}
		cout << score << '\n';
		file.close();
	}
	return 0;
}

int get_correct_value(char opponent, char player)
{
	int draw = 3;
	int win = 6;
	int rock = 1;
	int paper = 2;
	int siccors = 3;

	if (opponent == 'A') {
		if (player == 'X') {
			return siccors;
		}
		else if (player == 'Y') {
			return rock + draw;
		}
		else if (player == 'Z') {
			return paper + win;
		}
	}
	else if (opponent == 'B') {
		if (player == 'X') {
			return rock;
		}
		else if (player == 'Y') {
			return paper + draw;
		}
		else if (player == 'Z') {
			return siccors + win;
		}
	}
	else
	{
		if (player == 'X') {
			return paper;
		}
		else if (player == 'Y') {
			return siccors + draw;
		}
		else {
			return rock + win;
		}
	}
	return 0;
}