#include<iostream>
#include<vector>

using namespace std;

/*
State Space
===========
S = {(i,j) | 0<=i<=n, i<=j<=n}

Subproblem definition
===========
dp[i][j] = longest palindromic subsequence in string from index i to j

Optimal Substructure
===================
If dp[i][j] is the length of the longest subsequence from i to j then the dp[i-1][j+1] is length of longest palindromic 
subsequnce from i+1 to j-1 in string


Recursive Relation
====================
dp[i][j] = dp[i+1][j-1] + 2 if s[i] == s[j]
ow dp[i][j] = max(dp[i+1][j], dp[i][j-1])

end state 
==========
dp[0][n] = logest palindrome from 0 to n-1
*/

class LongestPlaindrome{

public:
int LongestPlaindromeLength(string s){
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<vector<string>> optimizedSol(n+1, vector<string>(n+1, ""));
    //base case 
    for(int i = 0;i < n;i++){
        dp[i][i] = 1;
        optimizedSol[i][i] = s[i];
    }
    //iterate for lengths
    for(int l = 2;l <=n;l++){
        for(int i = 0;i+l-1<n;i++){
            int j = i+l-1;
            if (s[i] == s[j]){
    dp[i][j] = dp[i+1][j-1] + 2;
    optimizedSol[i][j] = s[i] + optimizedSol[i+1][j-1] + s[j];
}
else if(dp[i+1][j] > dp[i][j-1]){
        dp[i][j] = dp[i+1][j];
        optimizedSol[i][j] = optimizedSol[i+1][j];
        }
        else{
            dp[i][j] = dp[i][j-1];
            optimizedSol[i][j] =  optimizedSol[i][j-1];
        }
    }}
    cout<<optimizedSol[0][n-1];
     return dp[0][n-1];
}
   
    

};

int main(){
    string s = "character";
    LongestPlaindrome l;
    cout<<l.LongestPlaindromeLength(s);
    return 0;
}