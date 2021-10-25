#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> sortedSquares(vector<int>& nums) {
        int start = 0;
        for(int i=1; i<nums.size(); i++){
            if(abs(nums[i]) < abs(nums[start]))
                start = i;
        }
        
        int left = start - 1;
        int right = start;
        
        vector<int> sq;
        while(left > -1 && right < nums.size()){
            if(abs(nums[left]) > abs(nums[right])){
                sq.push_back(nums[right] * nums[right]);
                right++;
            }
            else{
                sq.push_back(nums[left] * nums[left]);
                left--;
            }
        }
        while(left > -1){
            sq.push_back(nums[left] * nums[left]);
            left--;
        }
        while(right < nums.size()){
            sq.push_back(nums[right] * nums[right]);
            right++;
        }
        return sq;
    }
