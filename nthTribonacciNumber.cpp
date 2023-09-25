// head recursive solution O(3^n) and O(1) space
class Solution1 {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1||n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};
// memoized head recursive solution O(n) time and O(n) space
class Solution2 {
public:
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return memoized(n,dp);
    }
    int memoized(int n,vector<int>&dp){
        if(n==0){
            dp[0]=0;
            return dp[0];
        }
        if(n==1||n==2){
            dp[n]=1;
            return dp[n];
        }
        if(dp[n]!=-1){
            return dp[n-1]+dp[n-2]+dp[n-3];
        }
        else{
            dp[n]=memoized(n-1,dp)+memoized(n-2,dp)+memoized(n-3,dp);
        }
        return dp[n];
    }
};
// pure dp solution without function calls O(n) time O(1) space
class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1;
        int d=0;
        for(int i=2;i<n;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        if(n==1||n==2) return 1;
        return d;
    }
};
