#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    pair<int, int> mini;
    pair<int, int> maxi;

    cin>>temp;
    mini.first = 0;
    mini.second = temp;
    maxi.first = 0;
    maxi.second = temp;

    for(int i=1; i<n; i++){
        cin >> temp;
        if (temp <= mini.second){
            mini.second = temp;
            mini.first = i;
        }
        if (temp > maxi.second){
            maxi.first = i;
            maxi.second = temp;
        }
    }
    int numChanges = maxi.first + (n-1 - mini.first);
    if(mini.first < maxi.first) numChanges--;
    cout << numChanges;

}
