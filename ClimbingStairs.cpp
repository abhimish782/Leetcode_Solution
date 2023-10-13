// recursion tle
class Solution1 {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==0||n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }
    
};
// dp memoization 
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
    int helper(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0||n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        else{
        dp[n]=helper(n-1,dp)+helper(n-2,dp);
        }
        return dp[n];
    }
    
};
