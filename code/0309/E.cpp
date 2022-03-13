#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace::std;
 
struct location {
	int startX = 0, startY = 0, endX = 0, endY = 0;
};
 
vector <vector<int>> matrix(10, vector<int>(10));
vector <vector<int>> root(15, vector<int>(7, 0));
vector <int> carSize(15, 0);
vector <int> direct(15, 0); //if horizontal 1,vertical -1.
vector <location> loc(15);
int carCount = 0; //count how many cars
int mini = 100;
 
void findCarDirect() {
	for (int id = 1; id <= carCount; id++) {
		bool find = false;
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				if (matrix[i][j] == id) {
					if (matrix[i][j] == matrix[i][j + 1]) direct[id] = 1;
					else direct[id] = -1;
					find = true;
					break;
				}
			}
			if (find) break;
		}
	}
	return;
}
void findLocation() {
	for (int id = 1; id <= carCount; id++) {
		bool find = false;
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				if (matrix[i][j] == id) {
					loc[id].startX = i;
					loc[id].startY = j;
					find = true;
					break;
				}
			}
			if (find) break;
		}
	}
	for (int id = 1; id <= carCount; id++) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				if (matrix[i][j] == id) {
					loc[id].endX = i;
					loc[id].endY = j;
				}
			}
		}
	}
	return;
}
void makeRoot() {
	for (int id = 1; id <= carCount; id++) {
		if (direct[id] == 1) {
			root[id][loc[id].startY] = 1;
		}
		else {
			root[id][loc[id].startX] = 1;
		}
	}
	return;
}
void dfs(int steps) {
	if (steps + carSize[1] > 10) return;
	if (loc[1].endY == 6) {
		mini = min(mini, steps);
		return;
	}
	int sum = 0;
	for (int i = loc[1].startY; i <= 6; i++)sum += matrix[3][i];
	if (sum == carSize[1]) {
		mini = min(mini, steps);
		return;
	}
	for (int id = 2; id <= carCount; id++) {
		if (direct[id] == 1) {//horizontal
			if (loc[id].endY + 1 <= 6 && matrix[loc[id].endX][loc[id].endY + 1] == 0) {
				if (root[id][loc[id].startY + 1] == 0) {
					matrix[loc[id].endX][loc[id].endY + 1] = id;
					matrix[loc[id].endX][loc[id].startY] = 0;
					loc[id].endY++;
					loc[id].startY++;
					root[id][loc[id].startY] = 1;
					dfs(steps + 1);
					root[id][loc[id].startY] = 0;
					matrix[loc[id].endX][loc[id].endY] = 0;
					matrix[loc[id].endX][loc[id].startY - 1] = id;
					loc[id].endY--;
					loc[id].startY--;
				}
			}
			if (loc[id].startY - 1 > 0 && matrix[loc[id].endX][loc[id].startY - 1] == 0) {
				if (root[id][loc[id].startY - 1] == 0) {
					matrix[loc[id].endX][loc[id].startY - 1] = id;
					matrix[loc[id].endX][loc[id].endY] = 0;
					loc[id].endY--;
					loc[id].startY--;
					root[id][loc[id].startY] = 1;
					dfs(steps + 1);
					root[id][loc[id].startY] = 0;
					matrix[loc[id].endX][loc[id].startY] = 0;
					matrix[loc[id].endX][loc[id].endY + 1] = id;
					loc[id].endY++;
					loc[id].startY++;
				}
			}
 
		}
		else {//vertical;
			if (loc[id].endX + 1 <= 6 && matrix[loc[id].endX + 1][loc[id].endY] == 0) {//move the car down if it can
				if (root[id][loc[id].startX + 1] == 0) {
					matrix[loc[id].endX + 1][loc[id].endY] = id;
					matrix[loc[id].startX][loc[id].startY] = 0;
					loc[id].endX++;
					loc[id].startX++;
					root[id][loc[id].startX] = 1;
					dfs(steps + 1);
					root[id][loc[id].startX] = 0;
					matrix[loc[id].endX][loc[id].endY] = 0;
					matrix[loc[id].startX - 1][loc[id].startY] = id;
					loc[id].endX--;
					loc[id].startX--;
				}
			}
			if (loc[id].startX - 1 > 0 && matrix[loc[id].startX - 1][loc[id].startY] == 0) {//move the car up if it can
				if (root[id][loc[id].startX - 1] == 0) {
					matrix[loc[id].startX - 1][loc[id].startY] = id;
					matrix[loc[id].endX][loc[id].endY] = 0;
					loc[id].endX--;
					loc[id].startX--;
					root[id][loc[id].startX] = 1;
					dfs(steps + 1);
					root[id][loc[id].startX] = 0;
					matrix[loc[id].startX][loc[id].startY] = 0;
					matrix[loc[id].endX + 1][loc[id].endY] = id;
					loc[id].endX++;
					loc[id].startX++;
				}
			}
		}
	}
}
 
int main() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> matrix[i][j];
			carSize[matrix[i][j]]++;
			carCount = max(carCount, matrix[i][j]);
		}
	}
	findCarDirect();
	findLocation();
	makeRoot();
	if (loc[1].startX == loc[1].endX) {
		dfs(6-loc[1].endY);
	}
	if (mini == 100) cout << "-1\n";
	else cout << mini + carSize[1] << "\n";
}
