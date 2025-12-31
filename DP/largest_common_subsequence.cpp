#include<iostream>
#include<vector>
#include <climits>

using namespace std;

/*
State Space
S = {(i, j) | 0 ≤ i ≤ n1, 0 ≤ j ≤ n2}

dp[i][j] → length of the Longest Common Subsequence (LCS)
            between X[0..i-1] and Y[0..j-1]

Base Case
dp[i][0] = 0
dp[0][j] = 0

If either sequence is empty, the LCS length is 0.

Transition
If X[i-1] == Y[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Answer
dp[n1][n2]

Reconstruction
We maintain a direction matrix dir[i][j] to reconstruct the LCS:
    'd' → move diagonally (character is part of LCS)
    'u' → move up      (dp[i-1][j] chosen)
    'l' → move left    (dp[i][j-1] chosen)

Backtracking starts from (n1, n2) and follows dir to build the LCS.
*/



class Sol{
    public:
    vector<vector<char> > direction;
    int lcs(vector<int> &x, vector<int> &y){
        int n1 = x.size();
        int n2 = y.size();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1,INT_MIN));
        vector<vector<char> > lcs(n1+1, vector<char>(n2+1,'\0'));
           direction.assign(n1+1, vector<char>(n2+1, '\0'));
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
                    direction[i][j] = 'd';
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else if(dp[i][j-1] > dp[i-1][j]){
                    dp[i][j] = dp[i][j-1];
                    direction[i][j] = 'l';
                }
                else
                   { dp[i][j] =  dp[i-1][j];
                    direction[i][j] = 'u';}
            }
        }


        return dp[n1][n2];
    }

    string PrintLCS(vector<int> X, vector<int> Y){

        int n1 = X.size();
        int n2 = Y.size();
        string ans = "";
       while(n1>0 && n2>0){
            if(direction[n1][n2] == 'd'){
                ans.push_back(char('0' + X[n1-1]));
                n1--;
                n2--;
            }
            else if(direction[n1][n2] == 'u'){
               
                n1--;
            }
            else{
          
            n2--;}}
        reverse(ans.begin(), ans.end());
        return ans;
    }


    
    int spaceOptimized(vector<int> &x, vector<int> &y){
             int n1 = C.size();
         int n2 = y.size();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1,INT_MIN));
        vector<vector<char> > lcs(n1+1, vector<char>(n2+1,'\0'));
           direction.assign(n1+1, vector<char>(n2+1, '\0'));
        int prevx = 0;
        int prevy = 0
        //now when size!=0
        for(int i = 1; i <= n1;i++){
            for(int j = 1;j <= n2;j++){
                if(x[i-1] == y[j-1]){
                    direction[i][j] = 'd';
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else if(dp[i][j-1] > dp[i-1][j]){
                    dp[i][j] = dp[i][j-1];
                    direction[i][j] = 'l';
                }
                else
                   { dp[i][j] =  dp[i-1][j];
                    direction[i][j] = 'u';}
            }
            return ans;
    }
    //top down
    int topdown(vector<int> &X, vector<int> &Y){

        return 0;
    }};


int main(){
    vector<int> X = {1,2,3,4,5};
    vector<int> Y = {1,2,3,6};
    Sol s;
    cout<<s.lcs(X,Y)<<endl;
    cout<<"lcs is "<<s.PrintLCS(X,Y);

    return 0;
}