#include<iostream>
#include<vector>
using namespace std;

/*

Problem 
========
Given word lengths and a maximum line width, 
break the words into lines such that the sum of cubes of extra spaces in all non-last lines is minimized.
State Space
===========
S = {i | 0 <=i<=n}

Interpretation
==============
dp[i] = minimum cost to neatly print words from i to n-1

base case
=========
dp[n] = 0

Recursive relation
==================
used = sum(words[i..j]) + (j − i)   // spaces between words
extra = M − used
cost = extra * extra * extra
dp[i] = min over j {cost(i,j) + dp[i+1]}
  

Recursion Tree 
==============
 words = {3 2 2 5}
 index    1 2 3 4

                                 1 
                               /   \
                   take 3    [3]    [3 2]   take 3 and 2
                            /  \      / 
                take 2   [2] [2 2]  [2]    take 2 
                        /     /     /
                      [2]   [5]   [5]
                      /
                    [5]
*/

class Solution{

public:
    int minCost(vector<int> &words, int M){
    int l = words.size();
    vector<int> dp(l+1, INT_MAX);
    //base case 
    dp[l] = 0;
    for(int i = l-1;i >=0;i--){
        int currLen = 0;

        for(int j = i;j<l;j++){
            currLen+=words[j];
            int spaces = j-i;
            int used = currLen+spaces;
            if(used>M) break;
            int extra = M-used;
            int cost = (j == l-1)?0:extra*extra*extra;

            dp[i] = min(dp[i], cost+dp[j+1]);
        }
    }
    return dp[0];
    }

};

int main(){ 
    vector<int> words = {3,2,2,5};
    Solution sol;
    cout<<sol.minCost(words,6);
    return 0;
}


