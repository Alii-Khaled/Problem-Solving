#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int ShortestCommString(string str1, string str2, int i, int j,vector<vector<int>>& dp) {
	if (i == 0) return j;
	if (j == 0) return i;
	if (~dp[i][j]) return dp[i][j];

	if (str1[i - 1] == str2[j - 1]) {
		dp[i][j] = 1 + ShortestCommString(str1, str2, i - 1, j - 1, dp);
	}
	else {
		dp[i-1][j] = ShortestCommString(str1, str2, i - 1, j, dp);
		dp[i][j - 1] = ShortestCommString(str1, str2, i, j - 1, dp);
		dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
	}
	return dp[i][j];
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int ans;
	int sz1 = str1.size();
	int sz2 = str2.size();

	vector<vector<int>> dp(sz1+1,vector<int>( sz2+1, 0));

	for (int i = 0; i <= sz1; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= sz2; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i < sz1 + 1; i++) {
		for (int j = 1; j < sz2 + 1; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[sz1][sz2];
	return 0;
}