#include<iostream>
#include<vector>
#include <climits>
using namespace std;

//given a rod of length n and a vector of prices for each length
//we are supposed to find maximum profit we can get by cutting the rod however we want.

//bottoms up -> dp[0]->dp[1]->.....->dp[n]



class Solution{
public:
    int rodCutTopDown(vector<int> &price, int n){
        if(n == 0)
        return 0;
        int q = INT_MIN;
        for(int i = 0;i < n;i++){
            q = max(q, price[i]+rodCutTopDown(price,n-i-1));
        }
        return q;
    }

    int rodCutBottomsUp(vector<int> &price, int n){
        vector<int> dp(n+1, -1);
        //base case
        dp[0] = 0;
        
        for(int i = 1;i <= n;i ++){
            int q = INT_MIN; 
            for(int j = 0;j<i;j++){
                 q= max(q, price[j]+dp[i-j-1]);
            }
            dp[i] = q;
        }
        return dp[n];

    }
};

int main()
{
    vector<int> prices = {1,5,8,9,10,17,17,20,24,30}; 
    int n = prices.size();
    Solution S;
    cout<<S.rodCutBottomsUp(prices, n)<<endl;
    cout<<S.rodCutTopDown(prices, n)<<endl;
    return 0;
}