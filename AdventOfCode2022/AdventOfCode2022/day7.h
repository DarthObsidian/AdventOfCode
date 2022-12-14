#pragma once

#include <string>
using std::string;
using std::stoi;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::getline;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::smatch;

#include <algorithm>
using std::find;

struct sized_file {
	string name;
	int size;
};

struct directory {
	string name;
	vector<directory> children;
	vector<sized_file> file_sizes;
};

int do_day_seven();

int get_directory_sizes(ifstream&, int&);

int day_seven_part_two();

