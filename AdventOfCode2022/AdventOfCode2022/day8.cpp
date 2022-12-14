#include "day8.h"

using std::vector;
using std::string;
using std::ifstream;
using std::cout;

vector<string> map;
int highest_view_score = 0;

int do_day_eight() {
	ifstream file;
	string line;
	file.open("./dayEightInput.txt");
	if (file.is_open()) {
		int result = 0;
		while (getline(file, line)) {
			map.push_back(line);
		}
		file.close();
	}
	cout << get_visible_trees() << '\n';
	return 0;
}

int get_visible_trees() {
	int trees = 0;
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].length(); ++j) {
			int height = map[i][j] - '0';
			
 			string first_half = map[i].substr(0, j);
			reverse(first_half.begin(), first_half.end());
			int rightScore = 0;
			bool right_blocked = false;
			for (auto thing : first_half) {
				++rightScore;
				if (thing - '0' >= height) {
					right_blocked = true;
					break;
				}
			}

			string second_half = map[i].substr(j + 1);
			int leftScore = 0;
			bool left_blocked = false;
			for (auto next : second_half) {
				++leftScore;
				if (next - '0' >= height) {
					left_blocked = true;
					break;
				}
			}

			bool up_blocked = false;
			int upScore = 0;
			for (int x = i - 1; x >= 0; --x) {
				++upScore;
				if (map[x][j] - '0' >= height) {
					up_blocked = true;
					break;
				}
			}

			int downScore = 0;
			bool down_blocked = false;
			for (int z = i + 1; z < map.size(); ++z) {
				++downScore;
				if (map[z][j] - '0' >= height) {
					down_blocked = true;
					break;
				}
			}

			if (!right_blocked || !left_blocked || !up_blocked || !down_blocked) {
				++trees;
			}
			int total_score = rightScore * leftScore * upScore * downScore;
			if (total_score > highest_view_score) {
				highest_view_score = total_score;
			}
		}
	}
	return trees;
}

int day_eight_part_two() {
	cout << highest_view_score << '\n';
	return 0;
}