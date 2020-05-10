#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    string str;
    cin>>str;

    int aCnt = 0, bCnt = 0, cCnt = 0;
    int i=0;
    while(str[i] == 'a'){
        aCnt++;
        i++;
    }
    while(str[i] == 'b'){
        bCnt++;
        i++;
    }

    if(str[i] == 'a' || aCnt == 0 || bCnt == 0)   cout<<"NO";
    else{
        while(str[i] == 'c'){
            cCnt++;
            i++;
        }
        if(i<str.size() || (cCnt!=bCnt && cCnt !=aCnt)) cout<<"NO";
        else    cout<<"YES";
    }

return 0;
}
