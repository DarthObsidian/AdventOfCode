#include "day4.h"

using std::ifstream;
using std::string;
using std::regex;
using std::regex_token_iterator;
using std::vector;
using std::cout;

int do_day_four() {
	ifstream file;
	string line;
	file.open("./dayFourInput.txt");
	if (file.is_open()) {
		regex r{ "[[:digit:]]+" };
		regex_token_iterator<string::iterator> end;
		int num_fully_contained = 0;

		while (getline(file, line)) {
			regex_token_iterator<string::iterator> a{ line.begin(), line.end(), r };
			vector<int> matches;
			while (a != end) {
				matches.push_back(stoi(*a++));
			}
			if ((matches[0] <= matches[2] && matches[1] >= matches[3]) || (matches[0] >= matches[2] && matches[1] <= matches[3])) {
				num_fully_contained++;
			}
		}
		cout << num_fully_contained << '\n';
		file.close();
	}
	return 0;
}

int day_four_part_two() {
	ifstream file;
	string line;
	file.open("./dayFourInput.txt");
	if (file.is_open()) {
		regex r{ "[[:digit:]]+" };
		regex_token_iterator<string::iterator> end;
		int num_fully_contained = 0;

		while (getline(file, line)) {
			regex_token_iterator<string::iterator> a(line.begin(), line.end(), r);
			vector<int> matches;
			while (a != end) {
				matches.push_back(stoi(*a++));
			}
			if ((matches[0] <= matches[2] && matches[1] >= matches[2]) 
				|| (matches[0] <= matches[3] && matches[1] >= matches[3])
				|| (matches[2] <= matches[0] && matches[3] >= matches[0]) 
				|| (matches[2] <= matches[1]) && matches[3] >= matches[1]) {
				num_fully_contained++;
			}
		}
		cout << num_fully_contained << '\n';
		file.close();
	}
	return 0;
}
