#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int best1 = nums[0];
        int best2 = nums[1];
        int currBest;
        for(int i=2; i<nums.size(); i++){
            if(best1 + nums[i] > best2){
                currBest = best1 + nums[i];
                best1 = best2 > best1?best2:best1;
                best2 = currBest;
            }
            else{
                currBest = best2;
                best2 = best1 + nums[i];
                best1 = currBest;
            }
        }
        return best1>best2? best1:best2;
    }
