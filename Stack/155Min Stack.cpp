#include<iostream>
#include<stack>
#include<utility>
using namespace std;
//make a pair to keep track of minimum
class Solution{
public:
stack<pair<int,int> > st;
Solution(){}
void push(int x){
if(st.empty()){
st.push({x,x});
return ;}
st.push({x, min(x, st.top().second)});
}
void pop(){
    st.pop();
}
int top(){
    return st.top().first;
}
int mini(){
    return st.top().second;
}

};

int main(){
    Solution sol;
    sol.push(1);
    sol.push(2);
    sol.push(3);
    cout<<"top is "<<sol.top()<<endl;
    cout<<"min is "<<sol.mini()<<endl;
    return 0;
}
