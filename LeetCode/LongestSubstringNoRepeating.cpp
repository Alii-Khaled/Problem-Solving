#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int lengthOfLongestSubstring(string s) {
    if(s.size() == 0) return 0;
    
    int wLeft = 0;
    int wRight = 1;
    unordered_map<char, int> counts;
    
    int ans = 1;
    counts[s[0]] = 1;
    int temp = 1;
    while(wRight < s.size()){
        if (counts[s[wRight]] == 0){
            counts[s[wRight]]++;
            wRight++;
            temp++;
            if(temp > ans){
                ans = temp;
            }
        }
        else{
            counts[s[wLeft]]--;
            wLeft++;
            temp--;
        }
    }
    return ans;
}