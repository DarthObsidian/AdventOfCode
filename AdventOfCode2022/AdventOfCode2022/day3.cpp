#include "day3.h"

const int upper_offset = 38;
const int lower_offset = 96;

int do_day_three() {
	ifstream file;
	string line;
	file.open("./dayThreeInput.txt");
	if (file.is_open()) {
		int result = 0;
		while (getline(file, line)) {
			string first_half = line.substr(0, line.size() / 2);
			string second_half = line.substr(line.size() / 2);
			result += calculate_result(first_half, second_half);
		}

		cout << result << '\n';
		file.close();
	}
	return 0;
}

int calculate_result(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	string intersection;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));

	for (auto character : intersection) {
		if (isupper(character)) {
			return character - upper_offset;
		}
		else {
			return character - lower_offset;
		}
	}
	return 0;
}

int day_three_part_two() {
	ifstream file;
	string line1;
	string line2;
	string line3;
	file.open("./dayThreeInput.txt");
	if (file.is_open()) {
		int result = 0;
		while (getline(file, line1)) {
			getline(file, line2);
			getline(file, line3);
			result += calculate_part_two(line1, line2, line3);
		}

		cout << result << '\n';
		file.close();
	}
	return 0;
}

int calculate_part_two(string a, string b, string c) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	string intersection;
	string final_intersection;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersection));
	set_intersection(intersection.begin(), intersection.end(), c.begin(), c.end(), back_inserter(final_intersection));

	for (auto character : final_intersection) {
		if (isupper(character)) {
			return character - upper_offset;
		}
		else {
			return character - lower_offset;
		}
	}
	return 0;
}