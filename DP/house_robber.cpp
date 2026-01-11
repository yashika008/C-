#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    /*
    State space 
    =============
    S = { i | 0<=i<=j}
    
    Interpretation
    ==============
    dp[i] = maximum amount of money the theif can rob when at house i
    
    Recursive relation
    ==================
    dp[i] = max(dp[i-1], dp[i-2]+nums[i])
    
    i.e..., At house i, maximum mony that can be robbed is either by robbing the prev house and skipping current house or robbing current house
    
    base case
    =========
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    
    end case
    =========
    dp[n-1]
    
    
    
    */
    
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+1,0);
            //base case 
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2;i <n;i++){
                dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            }
            return dp[n-1];
        }
    };

int main(){
    vector<int> nums = {1,2,3,1};
    Solution sol;
    cout<<sol.rob(nums);
    return 0;
}