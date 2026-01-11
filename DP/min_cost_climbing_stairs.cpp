#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
State Space
===========
S = {i | 0<=i<n}
i is the step

Interpretation
==============
dp[i] = minimum cost to reach the ith step

Recursive relation
==================
dp[i] = min(dp[i-1], dp[i-2]) + nums[i]

Base case
=========
dp[0] = nums[0]
dp[1] = nums[1]

End case
========
dp[n] = next to last
 
*/
class Solution {
    public:
        int minCostClimbingStairs(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, INT_MAX);
            dp[0] = nums[0];
            dp[1] = nums[1];
            for(int i = 2;i < n;i++){
                dp[i] = min(dp[i-1], dp[i-2]) + nums[i];
            }
            
            return dp[n-1];
        }
    };

int main(){
vector<int> cost = {1, 3 ,4,3};
Solution sol;
cout<<sol.minCostClimbingStairs(cost);
return 0;
}