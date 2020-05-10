#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long long FrequencyPairs(vector<long long> vec) {
	unordered_map<long long, long long> hash;
	long long size = vec.size();
	for (long long i = 0; i < size; i++) {
		hash[vec[i]]++;
	}

	long long cnt = 0;
	for (auto i : hash) {
		for (auto j : hash) {
			if (i.second >= j.first && j.second >= i.first) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	vector<long long> vec;
	long long tmp;
	while (cin >> tmp) {
		vec.push_back(tmp);
	}

	long long out = FrequencyPairs(vec);

	// for Debugging. ( s was set of pairs )
	/*for (auto i: s) {
		cout << i.first << " " << i.second << endl;
	}
	*/
	cout << out;
	return 0;
}