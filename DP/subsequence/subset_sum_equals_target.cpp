#include<iostream>
#include<vector>
using namespace std;

/*
Problem statement
=================
Given an array of positive integers determine if target can be made from any subset


This is a classic 0/1 knapsack or take not take problem 

Recursion
=========
nottake  = f(index+1, target)\
take  = if(target >= nums[index]) f(index+1, target-nums[index])
f(index, target) = take || nottake

State
=====
S = {(index, target) | 0<=index<size | 0<=target<=TARGET}

Interpretation
===============
dp[index][target] = true  
if there exists a subset of nums[i..n-1] whose sum is t


Base case  
========== 



 */

class subsetSum
{
public:
bool helper_recursion(vector<int> &nums, int target, int index){
    if(target == 0) return true;
    if(index==nums.size()) return false;
    bool take = false;
    if(target >= nums[index])
    take = helper_recursion(nums, target-nums[index], index+1);
    bool nottake = helper_recursion(nums, target, index+1);

    return take || nottake;
}

//bottom_up
bool TargetExists_bottomup(vector<int> &nums, int target){
    vector<vector<bool>> dp(nums.size(), vector<bool>(target+1,false));
int n = nums.size();
//base case 
for(int i =0;i<n;i++)
dp[i][0] = true;

if(target >= nums[0])
dp[0][nums[0]] = true;

for(int i = 1;i<n;i++){
    for(int j = 1;j<=target;j++){
        int nottake = dp[i-1][j];
        int take = false;
        if(nums[i] <= j){
            take = dp[i-1][j-nums[i]];
        }
        dp[i][j] = take||nottake;
    }
}

return dp[n-1][target];
}

//top down 
bool helper_top_down(vector<int> &nums, int target,int index,vector<vector<int>> &dp){
    if(target == 0) return dp[index][target] = true;
    if(index==nums.size()-1) return dp[index][target] = (target==nums[index]);
    
    if(dp[index][target] != -1) return dp[index][target];
    bool take = false;
    if(target >= nums[index])
    take = helper_top_down(nums, target-nums[index], index+1,dp);
    bool nottake = helper_top_down(nums, target, index+1,dp);

    return dp[index][target] = take || nottake;
}


bool TargetExists(vector<int> &nums, int target){
    vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
return TargetExists_bottomup(nums, target);
}

};

int main(){
    vector<int> nums = {1,2,4};
    subsetSum s;
    cout<< s.TargetExists(nums, 3);
    return 0;
}