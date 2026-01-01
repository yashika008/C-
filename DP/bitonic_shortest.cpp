#include<iostream> 
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

/*

Problem statement 
=================
Find the minimum-length path that starts at the leftmost point, moves strictly rightward to the rightmost 
point, and then moves strictly leftward while visiting every point exactly once.

State Space
===========
S = {(i, j) | 1<=i<=n i<j<=n}

Interpretation
==============
points p1,....pn are sorted in increasing x order
dp[i][j] = length of shortest bitonic path that include all points from p1 to pj and open ends are pi and pj

Subproblem statement
====================
if dp[i][j] = length of shortest bitonic path then dp[i][j-1] is also shortest bitonic path that include all points from p1 to pj-1 and open ends are pi and pj-1

Base Case
=========
dp[1][2] = dist(p1,p2)
p1------p2

Recursive relation
===================
if i < j-1
dp[i][j] = dp[i][j-1] + dist(j-1,j)
p1--------pi
 \
  \_ _ _ _ p_(j-1)-----p(j)

if i = j-1 
p1
 \_ _ _p(j-1)
 dp[i][j] = dp[1][j-1] + dist(1,pj)

p1-----p2- - - -pj
  \_ _ _ _ p(j-1)  

 dp[i][j] = dp[2][j-1] + dist(2,pj)
 

 we have to find min of all. When i = j-1 
 dp[i][j] = min k < j-1 {dp[k][j-1] + dist(pk, pj)}


 End Case
 ========
 dp[1][n] + dist(1,n)= length of shortest bitonic sequence from 1 to n
  */

class Solution{
    public:
    double dist(int x1, int y1, int x2, int y2){
        double answer = 0;
        answer = sqrt(pow((x2-x1),2)+pow(y2-y1, 2));
        return answer;
    }

    double shortestBitonic(vector<vector<int>> &coordinates){
        int n = coordinates.size();
        vector<vector<double>> dp(n+1, vector<double>(n+1,INT_MAX));
        //base case
        dp[1][2] = dist(coordinates[0][0], coordinates[0][1],coordinates[1][0],coordinates[1][1]);

        //recursive relation
        for (int j = 3; j <= n; j++) {
            for (int i = 1; i < j; i++){
                if(i < j-1){
                    dp[i][j] = dp[i][j-1] + dist(coordinates[j-2][0], coordinates[j-2][1],coordinates[j-1][0],coordinates[j-1][1]);
                }
                else if(i == j-1){
                    for(int k = 1; k < j-1;k++){
                        dp[i][j] = min(dp[i][j], dp[k][j-1] + dist(coordinates[k-1][0], coordinates[k-1][1],coordinates[j-1][0],coordinates[j-1][1]));
                    }
                }
            }
        }

        return dp[1][n]+ dist(coordinates[0][0], coordinates[0][1],
            coordinates[n-1][0], coordinates[n-1][1]);;
    }
};

  int main(){
    //sorted
    vector<vector<int>> coordinates = {{0,6}, {1,0}, {2,3} ,{5,4} ,{6,1}, {7,5}, {8,2}};
    Solution sol;
    cout<<sol.shortestBitonic(coordinates);
    return 0;
  }