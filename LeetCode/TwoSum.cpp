#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0;
    int end = numbers.size() - 1;
    vector<int> ans;
    
    int sum;
    while(end != start){
        sum = numbers[start] + numbers[end];
        if (sum > target){
            end--;
        }
        else if(sum < target){
            start++;
        }
        else{
            
            ans.push_back(start+1);
            ans.push_back(end+1);
            break;
        }
    }
    return ans;
}