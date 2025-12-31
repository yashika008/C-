#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
struct Node{
int data;
Node* left;
Node* right;

Node(int root){
this->data = root;
this->left = NULL;
this->right = NULL;
}
};



vector<vector<int>> OBST(vector<double> &p, vector<double> &q){

    int n = p.size();

    vector<vector<double>> dp(n+2,vector<double>(n+1,0));
    vector<vector<double>> w(n+2,vector<double>(n+1,0));
    vector<vector<int>> root(n+1,vector<int>(n+1,0));

    for(int i = 1;i < n+2;i++){
        dp[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    
    for(int l = 1;l <= n;l++){
        
        for(int i = 1;i +l-1<=n;i++){
            int j = i+l-1;
            w[i][j] = w[i][j-1] + p[j-1]+ q[j];
            dp[i][j] = 1e18;
            for(int r = i;r<=j;r++){
                
                double t = dp[i][r-1] + dp[r+1][j]+w[i][j];
                if(t < dp[i][j]){
                root[i][j] = r;
            dp[i][j] = t;} 
            }
        }
    }
    return root;
} 

Node* buildOBST(vector<vector<int>> &root, int i, int j){
    if(j < i) return NULL;
    int r = root[i][j];
    Node* n = new Node(r);

    n->left = buildOBST(root, i, r-1);
    n->right = buildOBST(root, r+1, j);
    return n;
}

void Display(Node* t,  vector<string> &given){
    if(!t) return;

    cout<< given[t->data-1]<<" ";
    Display(t->left, given);
    Display(t->right, given);
    

}
};

int main(){
        vector<string> given = {"ate", "a", "pizza", "I", "only"};
        vector<double>
        p = {0.15, 0.10, 0.05, 0.10, 0.20},
        q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
        Solution sol;
        vector<vector<int>> ans = sol.OBST(p,q);
        
        Solution::Node* ans1 = sol.buildOBST(ans, 1, p.size());
        sol.Display(ans1, given);
        return 0;
}