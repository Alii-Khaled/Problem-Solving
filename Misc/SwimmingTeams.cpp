#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BestSwimTeam(vector<int> vec[2], int n) {
	int x1, x2;
	if (n == 0) return 0;

	x1 = vec[0][0];
	x2 = vec[1][0];
	int tmp;
	for (int i = 1; i < n; i++) {
		tmp = x1;
		x1 = max(x1, x2 + vec[0][i]);
		x2 = max(x2, tmp + vec[1][i]);
	}
	return max(x1, x2);
}
int main()
{
	int n;
	cin >> n;

	vector<int> swimmers[2];
	int tmp;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			swimmers[j].push_back(tmp);
		}
	}

	int bestTeam;
	bestTeam = BestSwimTeam(swimmers, n);
	cout << bestTeam;
	return 0;
}
