#include "day6.h"


int do_day_six() {
	ifstream file;
	string line;
	file.open("./daySixInput.txt");
	if (file.is_open()) {
		string line;
		getline(file, line);
		vector<char> last_four;
		vector<char> sorted;
		int found = -1;

		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			sort(sorted.begin(), sorted.end());
			if (last_four.size() == 4 && adjacent_find(sorted.begin(), sorted.end()) == sorted.end() ) {
				found = i;
				break;
			}
			if (last_four.size() >= 4) {
				last_four.erase(last_four.begin());
			}
			last_four.push_back(c);
			sorted = last_four;
		}
		cout << found << '\n';
	}
	return 0;
}

int day_six_part_two() {
	ifstream file;
	string line;
	file.open("./daySixInput.txt");
	if (file.is_open()) {
		string line;
		getline(file, line);
		vector<char> last_four;
		vector<char> sorted;
		int found = -1;

		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			sort(sorted.begin(), sorted.end());
			if (last_four.size() == 14 && adjacent_find(sorted.begin(), sorted.end()) == sorted.end()) {
				found = i;
				break;
			}
			if (last_four.size() >= 14) {
				last_four.erase(last_four.begin());
			}
			last_four.push_back(c);
			sorted = last_four;
		}
		cout << found << '\n';
	}
	return 0;
}