#include "day1.h"

int do_day_one() {
	ifstream file;
	file.open("./dayOneInput.txt");
	if (file.is_open()) {
		vector<int> sums;
		string line;
		int current_sum = 0;
		while (getline(file, line)) {
			if (line.empty()) {
				sums.push_back(current_sum);
				current_sum = 0;
				continue;
			}
			current_sum += stoi(line);
		}
		file.close();
		auto largest = max_element(sums.begin(), sums.end());
		cout << "Largest element is " << *largest << '\n';
	}

	return 0;
}

int day_one_part_two() {
	ifstream file;
	file.open("./dayOneInput.txt");
	if (file.is_open()) {
		vector<int> sums;
		string line;
		int current_sum = 0;
		while (getline(file, line)) {
			if (line.empty()) {
				sums.push_back(current_sum);
				current_sum = 0;
				continue;
			}
			current_sum += stoi(line);
		}
		file.close();
		sort(sums.begin(), sums.end(), std::greater<>());

		cout << "Largest three is " << sums[0] + sums[1] + sums[2] << '\n';
	}

	return 0;
}
