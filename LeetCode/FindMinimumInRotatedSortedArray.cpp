#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int findMin(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int mid;
    
    while((left - right) > 1 || (left - right) < -1){
        mid = (left+right)/2;
        if(nums[left] > nums[right] && nums[mid] > nums[left]){
                left = mid;
        }
        else{
            right = mid;
        }
    }
    return min(nums[left], nums[right]);
}
