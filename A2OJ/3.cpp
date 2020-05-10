#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    string orig,  mc;

    cin>> n >> orig >> mc;

    int cnt=0;
    int diff;
    for (int i=0; i < n; i++){
        diff = abs(orig[i] - mc[i]);
        if (diff > 5) diff = 10 - diff;
        cnt += diff;
    }
    cout << cnt;

return 0;
}
