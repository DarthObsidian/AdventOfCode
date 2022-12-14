#include "day7.h"

using std::ifstream;
using std::cout;
using std::string;
using std::vector;
using std::regex;
using std::smatch;

int needed_space = 0;
int smallest = 0;
int total_taken = 0;

int do_day_seven() {
	ifstream file;
	file.open("./daySevenInput.txt");
	int sum = 0;
	if (file.is_open()) {
		total_taken = get_directory_sizes(file, sum);
		file.close();
	}
	cout << sum << '\n';
	return 0;
}


int day_seven_part_two() {
	int total_space = 70000000;
	smallest = 30000000;
	ifstream file;
	file.open("./daySevenInput.txt");
	if (file.is_open()) {
		needed_space = smallest - (total_space - total_taken);
		int discard = 0;
		get_directory_sizes(file, discard);
		file.close();
	}
	cout << smallest << '\n';
	return 0;
}

int get_directory_sizes(ifstream& file, int& sum) {
	string line;
	vector<string> children;
	int file_size_sum = 0;
	while (getline(file, line)) {
		if (isdigit(line[0])) {
			regex r{ "[[:digit:]]+" };
			smatch match;
			regex_search(line, match, r);
			file_size_sum += stoi(match[0]);
		}
		else if (line.find("$ ls") != string::npos) {
			continue;
		}
		else if (line.find("$ cd ..") != string::npos) {
			if (file_size_sum <= 100000) {
				sum += file_size_sum;
			}
			if (file_size_sum >= needed_space && file_size_sum < smallest) {
				smallest = file_size_sum;
			}
			return file_size_sum;
		}
		else if (line.find("$ cd") != string::npos) {
			file_size_sum += get_directory_sizes(file, sum);
		}
	}
	if (file_size_sum <= 100000) {
		sum += file_size_sum;
	}
	if (file_size_sum > needed_space && file_size_sum < smallest) {
		smallest = file_size_sum;
	}
	return file_size_sum;
}