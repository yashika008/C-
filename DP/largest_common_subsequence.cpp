#include<iostream>
#include<vector>
#include <climits>

using namespace std;

/*
State Space
S = {(i,j) | 0<i<=n1 0<j<=n2}
dp[i][j] -> largest subsequence with X till index i and Y till index j

Base State 
dp[0][i] = 0
dp[i][0] = 0
which means if any subsequence is empty, lcs is empty string 

Recursive relation 
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
i.e when last char of both seq dont match, only one of these can be a part of l.c.s, check which gives max

ans = dp[m-1][n-1]
*/ 


class Sol{
    public:
    //This is bottom up
    int lcs(vector<int> &x, vector<int> &y){
        int n1 = x.size();
        int n2 = y.size();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1,INT_MIN));
        //when size of either is zero
        for(int i = 0;i <= n1;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i <= n2;i++){
            dp[0][i] = 0;
        }
        //now when size!=0
        for(int i = 1; i <= n1;i++){
            for(int j = 1;j <= n2;j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
            }
        }

        return dp[n1][n2];
    }

    //top down
    int topdown(vector<int> &X, vector<int> &Y){
        
        return 0;
    }
};


int main(){
    vector<int> X = {1,2,3,4,5};
    vector<int> Y = {1,2,3,6};
    Sol s;
    cout<<s.lcs(X,Y);
    return 0;
}