#include "day5.h"

using std::ifstream;
using std::vector;
using std::string;
using std::regex;
using std::regex_token_iterator;
using std::cout;

int do_day_five() {
	ifstream file;
	file.open("./dayFiveInput.txt");
	if (file.is_open()) {
		vector<vector<char>> stacks{
			{ 'V', 'N', 'F', 'S', 'M', 'P', 'H', 'J' },
			{ 'Q', 'D', 'J', 'M', 'L', 'R', 'S' },
			{ 'B', 'W', 'S', 'C', 'H', 'D', 'Q', 'N' },
			{ 'L', 'C', 'S', 'R' },
			{ 'B', 'F', 'P', 'T', 'V', 'M' },
			{ 'C', 'N', 'Q', 'R', 'T' },
			{ 'R', 'V', 'G' },
			{ 'R', 'L', 'D', 'P', 'S', 'Z', 'C' },
			{ 'F', 'B', 'P', 'G', 'V', 'J', 'S', 'D' },
		};

		string line; 
		regex r{ "[[:digit:]]+" };
		regex_token_iterator<string::iterator> end;
		while (getline(file, line)) {
			regex_token_iterator<string::iterator> a{ line.begin(), line.end(), r };
			vector<int> matches;
			while (a != end) {
				matches.push_back(stoi(*a++));
			}
			for (int i = 0; i < matches[0]; i++) {
				int destination_index = matches[2] - 1;
				int origin_index = matches[1] - 1;
				stacks[destination_index].insert(stacks[destination_index].begin(), stacks[origin_index][0]);
				stacks[origin_index].erase(stacks[origin_index].begin());
			}
		}

		for (auto stack : stacks) {
			cout << stack[0];
		}
		cout << '\n';
		file.close();
	}
	return 0;
}

int day_five_part_two() {
	ifstream file;
	file.open("./dayFiveInput.txt");
	if (file.is_open()) {
		vector<vector<char>> stacks{
			{ 'V', 'N', 'F', 'S', 'M', 'P', 'H', 'J' },
			{ 'Q', 'D', 'J', 'M', 'L', 'R', 'S' },
			{ 'B', 'W', 'S', 'C', 'H', 'D', 'Q', 'N' },
			{ 'L', 'C', 'S', 'R' },
			{ 'B', 'F', 'P', 'T', 'V', 'M' },
			{ 'C', 'N', 'Q', 'R', 'T' },
			{ 'R', 'V', 'G' },
			{ 'R', 'L', 'D', 'P', 'S', 'Z', 'C' },
			{ 'F', 'B', 'P', 'G', 'V', 'J', 'S', 'D' },
		};

		string line; regex r{ "[[:digit:]]+" };
		regex_token_iterator<string::iterator> end;
		while (getline(file, line)) {
			regex_token_iterator<string::iterator> a{ line.begin(), line.end(), r };
			vector<int> matches;
			while (a != end) {
				matches.push_back(stoi(*a++));
			}
			for (int i = 0; i < matches[0]; i++) {
				int destination_index = matches[2] - 1;
				int origin_index = matches[1] - 1;
				stacks[destination_index].insert(stacks[destination_index].begin() + i, stacks[origin_index][0]);
				stacks[origin_index].erase(stacks[origin_index].begin());
			}
		}

		for (auto stack : stacks) {
			cout << stack[0];
		}
		cout << '\n';
		file.close();
	}
	return 0;
}