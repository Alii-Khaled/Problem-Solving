#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    string  str;
    cin >> str;
    map <char, int> mp;
    for(unsigned int i=0; i<str.size(); i++){
        mp[str[i]]++;
    }
    int cnt1s = 0;
    for (map<char, int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        if (itr->second == 1)   cnt1s++;
    }
    if(mp.size() > 4)   cout<<"No";
    else if(mp.size() == 2 && cnt1s>0)   cout<<"No";
    else if(mp.size() == 1)    cout<< "No";
    else if(mp.size() == cnt1s && cnt1s%2 == 1)  cout<< "No";
    else    cout<< "Yes";

    return 0;
}
