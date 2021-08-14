#include <iostream>
#include <vector>
using namespace std;

void Rec(vector<vector<int>> vec, int mask, int n, int cost, int& minCost) {
	if (n == 0) {
		if (cost < minCost) {
			minCost = cost;
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (i != mask) {
			Rec(vec, i, n - 1, cost + vec[n-1][i], minCost);
		}
	}
	return;
}
int minPrice(vector<vector<int>> cost) {
	int minCost = 1e9;
	int n = cost.size() - 1;
	cout << n;
	for (int i = 0; i < 3; i++) {
		Rec(cost, i, n, cost[n][i], minCost);
	}
	return minCost;
}

int main()
{
	int ans;
	int n, c;
	cin >> n >> c;
	vector<vector<int>> vec(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c; j++) {
			int tmp;
			cin >> tmp;
			vec[i].push_back(tmp);
		}
	}
	ans = minPrice(vec);
	cout << ans;
	system("Pause");
	return 0;
}
