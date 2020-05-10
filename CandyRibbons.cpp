#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> dp(n + 1);
	dp[0] = 0;
	int atemp, btemp, ctemp;
	for (int i = 1; i < n+1;i++) {
		atemp = btemp = ctemp = -1;
		if (i >= a) {
			atemp = 1 + dp[i - a];
		}
		if (i >= b) {
			btemp = 1 + dp[i - b];
		}
		if (i >= c) {
			ctemp = 1 + dp[i - c];
		}
		dp[i] = max(atemp, max(btemp, ctemp));
	}
	cout << dp[n];
	return 0;
}