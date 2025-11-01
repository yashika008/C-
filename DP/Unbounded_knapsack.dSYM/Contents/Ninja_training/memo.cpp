#include<iostream> 
using namespace std;
//problem link : https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/#:~:text=Problem%20Link%3A-,Ninja%20Training,-Problem%20Statement%3A
//dp[day][last] = maximum points on day with last option last

int helper(int n, vector<vector<int>> &points,vector<vector<int>> &dp, int day,int last){
    if(day < 0) return 0;
    if(dp[day][last]!=-1)
    return dp[day][last];
    int maxi = 0;
    for(int i = 0;i < 3;i++){
        if(i!=last)
        maxi = max(points[day][i]+helper(n, points, dp, day-1,i), maxi);
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //dp[i][j] = maximum on day 1 when last is j
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n, points, dp, n-1,3);
}
int main(){
    return 0;
}