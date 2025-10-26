#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int helper_recursion(vector<int>& cost, int index, int n){
        if(index == 0) return cost[0];
        if(index == 1) return min(cost[0], cost[1]);

        return cost[index] + min(helper_recursion(cost, index-1,n),helper_recursion(cost, index-2,n));
    }
    int helper_TD(vector<int>& cost, vector<int>& dp, int index){
        if(index<0)return 0;
        //from step 0 there is only one way
        if(index == 0) return cost[0];
        //from step 1 
        if(index == 1) return cost[1];
        if(dp[index]!=INT_MAX) return dp[index];
        return dp[index] = cost[index]+min(helper_TD(cost, dp, index-1),helper_TD(cost, dp, index-2));
    }
public:
    int minCostClimbingStairs_recursion(vector<int>& cost) {
        int n = cost.size();
        return min(helper_recursion(cost, n-1,n), helper_recursion(cost, n-2,n));
    }

    int minCostClimbingStairs_top_down(vector<int>& cost) {
        vector<int> dp(cost.size()+1,INT_MAX);
        return min(helper_TD(cost, dp, cost.size()-2), helper_TD(cost, dp, cost.size()-1));
    }
    //bottoms up iterative

    int minCostClimbingStairs_BUI(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i < cost.size();i++){
                dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }

    //bottoms up iterative space optimized

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = prev2;
        for(int i = 2;i < cost.size();i++){
                curr = cost[i]+min(prev1, prev2);
                prev1 = prev2;
                prev2 = curr;
        }
        return min(prev1, prev2);
    }

};
int main(){
    Solution s;
    vector<int> cost(4,1);
    cout<<s.minCostClimbingStairs_recursion(cost);
    return 0;
}