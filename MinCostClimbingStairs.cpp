// brute force tle
class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(findMin(cost,n-1),findMin(cost,n-2));
    }
    int findMin(vector<int>&cost,int n){
        if(n<0) return 0;
        if(n==0||n==1) return cost[n];
        return cost[n]+min(findMin(cost,n-1),findMin(cost,n-2));
    }
    
};
// memoization top down dynamic programming
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(findMin(cost,n-1,dp),findMin(cost,n-2,dp));
    }
    int findMin(vector<int>&cost,int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0||n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        else{
            dp[n]=cost[n]+min(findMin(cost,n-1,dp),findMin(cost,n-2,dp));
        }
        return dp[n];
    }
    
};
