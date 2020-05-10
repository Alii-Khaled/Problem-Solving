#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    string str;
    cin >> str;

    bool valid = true;
    bool fstChar = isupper(str[0]);
    for (int i=1; i<str.size(); i++){
        if(!isupper(str[i])){
            valid = false;
            break;
        }
    }

    if(valid){
        if (fstChar)    str[0] = tolower(str[0]);
        else    str[0] = toupper(str[0]);
        for (int i=1; i< str.size(); i++){
            str[i] = tolower(str[i]);
        }
    }
    cout << str;
return 0;
}
