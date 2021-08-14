#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int a1, a2, b1, b2, n, p1case1, p2case1, p1case2, p2case2, p1case3, p2case3, pl;
	cin >> n >> a1 >> a2 >> b1 >> b2;
	vector<vector<pair<int, int>>> ans[2];
	ans[0].resize(n + 1);       ans[1].resize(n + 1);
	for (int i = 0;i <= n;i++) {
		ans[0][i].resize(n + 1, { -1, -1 }), ans[1][i].resize(n + 1, { -1, -1 });
	}
		
	pair<int, int> p1, p2;

	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= n;j++) {
			for (int player = 0; player < 2; player++)
			{
				if (i == 0 && j == 0) {
					ans[player][i][j] = { player, 0 };
					continue;
				}
				if (i == 0) { 
					ans[player][i][j] = { 1, 0 };
					continue; 
				}
				if (j == 0) { 
					ans[player][i][j] = { 0, 0 };
					continue; 
				}

				if (player == 0)
				{
					p1case1 = i - a1;   p2case1 = j - a2;
					p1case2 = i;        p2case2= j - b1;
					pl = i;
				}
				else
				{
					p1case1 = i - a2;   p2case1 = j - a1;
					p1case2 = i - b1;   p2case2 = j;
					pl = j;
				}
				p1case3 = i - b2;     p2case3= j - b2;

				if (p1case1 <= 0 && p2case1 <= 0)  p1 = { 1 - player, 0 };
				else if (p1case1 <= 0)	p1 = { 1, 0 };
				else if (p2case1 <= 0)  p1 = { 0, 0 };
				else   p1 = ans[1 - player][p1case1][p2case1];

				if (pl % 3 == 0)
				{
					if (p1case2 <= 0 && p2case2 <= 0)	p2 = { 1 - player, 0 };
					else if (p1case2 <= 0)	p2 = { 1, 0 };
					else if (p2case2 <= 0)	p2 = { 0, 0 };
					else   p2 = ans[1 - player][p1case2][p2case2];
				}
				else
				{
					if (p1case3 <= 0 && p2case3 <= 0)	p2 = { 1 - player, 0 };
					else if (p1case3 <= 0)	p2 = { 1, 0 };
					else if (p2case3 <= 0)	p2 = { 0, 0 };
					else   p2 = ans[1 - player][p1case3][p2case3];
				}

				if (p1.first == player && p2.first == player)
					ans[player][i][j] = { player, 1 + max(p1.second, p2.second) };
				else if (p1.first == player)
					ans[player][i][j] = { player, 1 + p1.second };
				else if (p2.first == player)
					ans[player][i][j] = { player, 1 + p2.second };
				else
					ans[player][i][j] = { 1 - player, 1 + min(p1.second, p2.second) };
			}
		}
	}
	pair<int, int> p = ans[0][n][n];
	cout << p.first + 1 << " " << p.second << endl;
}
