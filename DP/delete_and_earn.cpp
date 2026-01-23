#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
Problem
=======
Leetcode: 740
Given an array nums find the maximum sum that can be obtained by doing following operations
-take nums[i], add it to the sum and then delete all entries equals to nums[i]-1 and nums[i]+1

State Space 
===========
S = {x | 0<=x<=maxVal}

Interpretation
==============
dp[x] = maximum we can earn from points 0 to x

Recursive Relation
==================
dp[x] = max(dp[x-1], dp[x-2]+points[x])
points[x] = freq of x * x
you can either take x or skip x
take x implies points[x] + maximum we can earn from points 0 to x-2 because we delete x-1
skip x implies maximum we can earn from points 0 to x-1

Base case
=========
dp[0] = 0
dp[1] = weight[1]

End case
========
dp[max]
*/

class Solution {
    public:
        int deleteAndEarn(vector<int>& nums) {
            int n = *max_element(nums.begin(),nums.end());
            vector<int>dp(n+1, 0);
            unordered_map<int,int> weight;
            for(auto i : nums){
                weight[i]+=i;
            }
            //base case
            dp[0] = 0;
            dp[1] = weight[1];
            
            for(int i = 2;i <= n;i++){
                dp[i] = max(dp[i-1], dp[i-2]+weight[i]);
            }
            return dp[n];
        }
    };

int main(){
    Solution sol;
    vector<int> nums = {2,2,3,3,4};
    cout<<sol.deleteAndEarn(nums);
    return 0;
}