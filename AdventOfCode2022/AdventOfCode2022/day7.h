#ifndef DAY7
#define DAY7

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

struct sized_file {
	std::string name;
	int size;
};

struct directory {
	std::string name;
	std::vector<directory> children;
	std::vector<sized_file> file_sizes;
};

int do_day_seven();

int get_directory_sizes(std::ifstream&, int&);

int day_seven_part_two();

#endif // !DAY7
