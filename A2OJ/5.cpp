#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, t;
    string q;
    cin >> n >> t;
    cin >> q;

    for (int j=0; j<t; j++){
        for (int i=0; i<n-1; i++){
            if(q[i]=='B' && q[i+1]=='G'){
                q[i] = 'G';
                q[i+1] = 'B';
                i++;
            }
        }
    }
    cout<<q;

return 0;
}
