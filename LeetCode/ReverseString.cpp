#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size() - 1;
    char temp;
    while(end > start){
        temp = s[end];
        s[end] = s[start];
        s[start] = temp;
        end--;
        start++;
    }
        
}