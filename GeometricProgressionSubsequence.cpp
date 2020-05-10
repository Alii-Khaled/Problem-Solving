#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long GeometricProgCount(vector<int> vec, int r) {
	long long count = 0;
	unordered_map <int, int> hashBack, hashFront;
	for (int i = 0; i < vec.size(); i++) {
		hashFront[vec[i]]++;
	}

	int xFront, xBack;
	for (int i = 0; i < vec.size(); i++) {
		hashFront[vec[i]]--;
		xFront = vec[i] * r;
		if (vec[i] % r != 0) {
			hashBack[vec[i]]++;
			continue;
		}
		xBack = vec[i] / r;
		count += (long long)hashFront[xFront] * hashBack[xBack];
		hashBack[vec[i]]++;
	}
	return count;
}
int main()
{
	int r;
	cin >> r;
	int tmp;
	vector<int> vec;
	unordered_map <int, int> hash;
	while (cin >> tmp) {
		vec.push_back(tmp);
		hash[tmp]++;
	}
	cout << GeometricProgCount(vec, r);
	return 0;
}