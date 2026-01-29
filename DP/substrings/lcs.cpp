#include<iostream>
using namespace std;


class LCS{
    public:
    int countLength(string s1, string s2){
            int n = s1.length();
            int m = s2.length();

            vector<vector<int>> dp(n+1,vector<int>(m+1,0));

            for(int i = 1;i <= n;i++){
                for(int j = 1;j<= m;j++){
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
                cout<< lcsString(s1,s2,dp)<<endl;
                return dp[n][m];
    }

string lcsString(string s1, string s2, vector<vector<int>>& dp){
        int i = s1.size();
        int  j = s2.size();
        string ans(dp[i][j], '$');
        int index = dp[i][j]-1;

           while(i>0 &&j>0){
                        if(s1[i-1] == s2[j-1]){
                            ans[index] = s1[i-1];
                            index--; 
                            i--;
                            j--;
                        }
                        else if(dp[i-1][j] > dp[i][j-1]){
                            i = i-1;
                        }
                        else{
                            j = j-1;
                        }
                }         
            return ans;
    }
};

int main(){
    string s1 = "abcde";
    string s2 = "bdgek";

    LCS lcs;
    cout<<lcs.countLength(s1,s2)<<endl;
    return 0;
}