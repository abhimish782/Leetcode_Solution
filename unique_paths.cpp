class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, m, n, dp);
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
        return dp[i][j];
    }
};
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=min(m,n)-1;
        double res=1;
        for(int i=1;i<=r;++i,N--){
            res=res*N/i;
        }
        return (int) res;
    }
};
