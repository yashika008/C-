#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
/*
Optimal substructure 
====================
Any subpath in the longest path is also the longest

State space and Subproblem definition
====================
S = {v | v is a node in G}
dp[v] = maximum total weight from s to v

Transition or recursion relation
====================
if there is an edge from v to u
dp[u] = max(dp[u], dp[v]+w(v,u))




*/

class Solution{


};

int main(){
    int V = 6;
    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({1,3});
    graph[0].push_back({2,6});
    graph[1].push_back({2,4});
    graph[1].push_back({3,4});
    graph[2].push_back({3,8});
    graph[3].push_back({4,2});
    
    int source = 0;
    vector<int> indegree(V,0);
    for(int i = 0; i <V;i++){
        for(auto edge : graph[i]){
            indegree[edge.first]++;
        }
    }
    queue<int> q;
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //topo sort =(Kahn)
    vector<int> topo;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for(auto i : graph[curr]){
            int v = i.first;
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    vector<int> dp(V, INT_MIN);
    dp[source] = 0;
    for(int i : topo){
if(dp[i] == INT_MIN) continue;
        for(auto edge : graph[i]){
            int v = edge.first;
            int weight = edge.second;
            dp[v] = max(dp[v], dp[i]+weight);
        }
    }
    cout<<dp[4];
    
    return 0;
}