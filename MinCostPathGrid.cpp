#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinCostPath(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> gridsol(n, vector<int>(m));
	gridsol[0][0] = grid[0][0];

	for (int i = 1; i < m; i++) {
		gridsol[0][i] = gridsol[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < n; i++) {
		gridsol[i][0] = gridsol[i - 1][0] + grid[i][0];
	}
	int minimumway;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m;j++) {
			minimumway = min(min(gridsol[i - 1][j - 1], gridsol[i][j - 1]), gridsol[i - 1][j]);
			gridsol[i][j] = minimumway + grid[i][j];
		}
	}
	return gridsol[n - 1][m - 1];
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n);
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			grid[i].push_back(tmp);
		}
	}
	cout << MinCostPath(grid);
	return 0;
}