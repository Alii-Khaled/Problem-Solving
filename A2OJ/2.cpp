#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m, a, b;
    cin>>n>>m>>a>>b;

    if (a*m <= b) cout<< n*a;

    else{
        int specialnum = n / m;
        int restnum = n - specialnum*m;
        if (restnum * a <= b) cout << restnum*a + specialnum*b;
        else    cout<< (specialnum+1) * b;
    }

return 0;
}
