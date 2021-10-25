#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void moveZeroes(vector<int>& nums) {
        int start = -1;
        for(int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                start = i;
                break;
            }
        }
        if(start == -1) return;
        
        for(int i=start + 1; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[start] = nums[i];
                nums[i] = 0;
                start++;
            }
        }
    }