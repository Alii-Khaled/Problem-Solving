#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinCoins(vector<int> coins, int sumValue) {
	int n = coins.size();
	vector<int> minCoins(sumValue + 1);
	minCoins[0] = 0;

	for (int i = 1; i <= sumValue; i++) {
		minCoins[i] = 1e9;
	}
	int tmp;
	//loop on all sumValues from 1 to the needed sumValue.
	for (int i = 1; i <= sumValue; i++) {
		//loop on all coins needed to form sumValue at the end.
		for (int j = 0; j < n; j++) {
			if (coins[j] <= i) {
				tmp = minCoins[i - coins[j]] + 1;
				minCoins[i] = min(minCoins[i], tmp);
			}
		}
	}
	return minCoins[sumValue];
}
int main()
{
	int sum, n;
	cin >> sum >> n;
	vector<int> coins;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coins.push_back(tmp);
	}
	cout << MinCoins(coins, sum);
	return 0;
}