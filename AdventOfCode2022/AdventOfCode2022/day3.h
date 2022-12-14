#pragma once

#include <string>
using std::string;
using std::getchar;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;
using std::stoi;

#include <algorithm>
using std::set_intersection;
using std::back_inserter;
using std::sort;

int do_day_three();
int calculate_result(string a, string b);
int day_three_part_two();
int calculate_part_two(string a, string b, string c);