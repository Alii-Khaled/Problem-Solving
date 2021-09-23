#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void recBackTrack(vector<vector<int>>& results, vector<int>& current, vector<int>& candidates, int remainder, int startIdx){
        if (remainder < 0) return;
        if (remainder == 0) {
            results.push_back(current);
            return;
        }
        for (int i=startIdx; i<candidates.size(); i++){
            current.push_back(candidates[i]);
            recBackTrack(results, current, candidates, remainder - candidates[i], i);
            current.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        recBackTrack(results, current, candidates, target, 0);
        return results;
    }
