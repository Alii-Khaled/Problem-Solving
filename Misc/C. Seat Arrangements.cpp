#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >>n >> m >> k;
    vector< vector<char> > mat(0);
    char tmp;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>tmp;
            mat[i]= tmp;
        }
    }
    cout<< mat[0][0];

    return 0;
}
