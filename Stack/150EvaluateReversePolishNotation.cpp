#include<iostream>
#include<stack>
using namespace std;

//Reverse Polish Notation - number stack mein rakhti ja and operators jaise hi stack ke upar ke 2 elements nikal ke operation lga dena

class Solution{
public:
int answer(vector<string> & Polish){
    int n = Polish.size();
    stack<int> st;
    //iterate over the vector
    for(int i = 0;i < n;i++){
        //if it is an operator take two numbers from stack top
        string current = Polish[i];
        if(current == "+" || current == "-" || current == "/" ||current == "*"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = 0;
            if(current == "+")  ans = b+a;
            else if(current == "-") ans = b-a;
            else if(current == "*") ans = b*a;
            else ans = b/a;
            st.push(ans); 
        } 
        // if it an operand
        else{
            st.push(stoi(current));
        }

    }
    return st.top();
}

};

int main(){
    vector<string> input;
    int size;
    cout<<"Enter Size : "<<endl;
    cin>>size;
    for(int i = 0;i < size;i++){
        string s;
        cin>>s;
        input.push_back(s);
    }
    Solution s;
    cout << s.answer(input);
    return 0;
}