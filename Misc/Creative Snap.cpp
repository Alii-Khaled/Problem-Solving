#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> pos;
ll A;
ll B;
ll creativeSnap(ll left, ll right);
int main() {
    ll n, k;

	cin >> n >> k >> A >> B;
	ll temp;

	for (int i=0; i<k; i++){
        cin >> temp;
        pos.push_back(temp);
	}
	sort(pos.begin(), pos.end());

	ll minPower = creativeSnap(1, pow(2, n));
	cout << minPower;

	return 0;
}

ll creativeSnap(ll left, ll right){

    ll numAvengers = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
    if (numAvengers == 0) return A;

    ll currentPower = B * numAvengers * (right - left + 1);
    if (left == right) return currentPower;

    ll mid = (right + left) / 2;

    return min(currentPower, creativeSnap(left, mid) + creativeSnap(mid+1, right));
}
