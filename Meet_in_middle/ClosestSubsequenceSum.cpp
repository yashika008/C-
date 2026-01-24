#include<iostream>
using namespace std;

/*
Problem Statement 
=================
find two subarrays such their sum is closest to given goal

It is be a DP problem 
Constraints:
1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109

so time complexity is 2^40 
*/

class Solution {
    public:
        void subsetSum(vector<int>& nums,  vector<int> &first,int index,int sum,int end){
            if(index >= end){
                first.push_back(sum);
                return ;
            }
            subsetSum(nums, first, index+1,sum+nums[index],end);
            subsetSum(nums, first, index+1,sum,end);
            return;
        }
    
     int binary(vector<int> &arr, int goal){
            int start = 0;
            int end = arr.size()-1;
                int closest = arr[start];
            while(start <= end){
                int mid = start + (end-start)/2;
                if(abs(goal-arr[mid]) < abs(goal-closest)){
                        closest = arr[mid];
                }
                if(goal == arr[mid])
                return arr[mid];
                else if(goal > arr[mid]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            return closest;
            
        }
    
        int minAbsDifference(vector<int>& nums, int goal) {
            int n = nums.size();
            int half = n/2;
            //make sum array
            vector<int> first;
            vector<int> second;
            //store all possible sums - recursion
            subsetSum(nums, first, 0,0,n/2);
            subsetSum(nums, second, n/2 ,0,n);
            sort(second.begin(), second.end());
            int ans = INT_MAX;
            for(int i = 0;i < first.size();i++){
                    int a = first[i];
                    int c = goal - a;
                
                int b = binary(second, c);
                ans = min(abs(goal-a-b), ans);
            }
    
    return ans;
                }
    };

int main(){
    vector<int> nums = {9152249,8464156,-2493402,8990685,-7257152,-1050240,2243737,-82901,8939692};
    int goal = 26915229;
    Solution sol;
    cout<<sol.minAbsDifference(nums,goal);
    return 0;
}