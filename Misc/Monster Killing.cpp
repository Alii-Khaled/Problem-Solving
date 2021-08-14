#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MinDmg(vector<int> weapons, int weapsize, int sumValue) {
	sort(weapons.begin(), weapons.end());

	int count = 0;
	//loop on all weapons needed to form sumValue at the end.
	for (int i = weapsize - 1; i >= 0; i--) {
		count += sumValue / weapons[i];
		sumValue = sumValue % weapons[i];
	}
	return count;
}

int main()
{
	int n, m;
	cin >> n;

	vector<int> monsters(n);
	for (int i = 0; i < n; i++) {
		cin >> monsters[i];
	}
	cin >> m;
	vector<int> weapons(m);
	for (int i = 0; i < m; i++) {
		cin >> weapons[i];
	}
	int mindmg;
	for (int i = 0; i < n; i++) {
		mindmg = MinDmg(weapons, m, monsters[i]);
		cout << mindmg << endl;
	}
	return 0;
}
