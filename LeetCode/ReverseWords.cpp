#include<iostream>
using namespace std;
#include<bits/stdc++.h>

string reverseWords(string s) {
    string result;
    string rev;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            rev += ' ';
            result += rev;
            rev = "";
        }
        else{
            rev = s[i] + rev;
        }
    }
    result += rev;
    
    
    return result;
}