#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> counts;
    
    int wLeft = 0;
    int wRight = 0;
    
    int numberChars = s1.size();
    for(int i=0; i<s1.size(); i++){
        counts[s1[i]]++;
    }
    
    while(wRight < s2.size()){
        if(counts[s2[wRight]] > 0){
            numberChars--;
            counts[s2[wRight]]--;
            wRight++;
        }
        else{
            if(counts[s2[wRight]] == 0 && numberChars == 0) 
                return true;
            else{
                numberChars++;
                counts[s2[wLeft]]++;
                wLeft++;
            }
        }
        
    }
    if(counts[s2[wRight]] == 0 && numberChars == 0) 
        return true;
    return false;
}