#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    int const sz = num1.size();
    for(int i=0; i < sz; i++){
        cout << ((num1[i] - '0') ^ (num2[i] - '0'));
    }
}
