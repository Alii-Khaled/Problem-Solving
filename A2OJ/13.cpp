#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    bool odd;

    if(n == 1) cout << -1 << " ";

    else{
        if (n % 2 == 1) odd = true;

        for (int i=1; i <= n; i++){
            if (odd && i+1 == n) {
                cout << i+1 << " " << i-1;
                break;
                }
            if(i % 2 == 1) {
                cout << i+1 << " ";
                }
            else    {
                cout << i-1 << " ";
                }
            }
    }
}
