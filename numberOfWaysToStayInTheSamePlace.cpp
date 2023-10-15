// backtracking solution O(3)
class Solution1 {
public:
    int len;
    int numWays(int steps, int arrLen) {
        len=arrLen;
        int cnt=0;
        search(steps,0,cnt);
        return cnt;
    }
    void search(int steps,int index,int &cnt){
        if(steps==0&&index==0){
            cnt++;
            return;
        }
        else if(steps<0) return;
        else if(index<0||index>=len) return;

        // left call
        if(index!=0){
            steps=steps-1;
            index=index-1;
            search(steps,index,cnt); 
            steps=steps+1;
            index=index+1;
        }
        // stay call
        steps=steps-1;
        //index=index-1;
        search(steps,index,cnt); 
        steps=steps+1;
        //index=index+1;

        // right call
        if(index<len){
            steps=steps-1;
            index=index+1;
            search(steps,index,cnt); 
            steps=steps+1;
            index=index-1;
        }
        return;
    }
};
// head recusive counting solution 
class Solution2 {
public:
    int len;
    int numWays(int steps, int arrLen) {
        return countWaysRec(steps,arrLen,0);
    }
    int countWaysRec(int steps,int arrLen,int idx){
        if(steps==0&&idx==0) return 1;
        else if(steps==0) return 0;
        else if(idx<0||idx>=arrLen) return 0;

        int left=countWaysRec(steps-1,arrLen,idx-1);
        int stay=countWaysRec(steps-1,arrLen,idx);
        int right=countWaysRec(steps-1,arrLen,idx+1);

        return left+stay+right;

    }
};
// memoized head recursive solution 
class Solution {
public:
    int MOD=1000000007;
    int numWays(int steps, int arrLen) {
        int maxPos = min(steps / 2, arrLen - 1);
        vector<vector<long long>>dp(steps+1,vector<long long>(maxPos+1,-1));
        return countWaysRec(steps,0,dp);
    }
    long long countWaysRec(int steps,int idx,vector<vector<long long>>&dp){
        if(steps==0&&idx==0) return 1;
        else if(steps==0) return 0;
        else if(idx<0||idx>=dp[0].size()) return 0;

        if(dp[steps][idx]!=-1) return dp[steps][idx];
        else{

            long long left=countWaysRec(steps-1,idx-1,dp);
            left=left%MOD;
            long long stay=countWaysRec(steps-1,idx,dp);
            stay=stay%MOD;
            long long right=countWaysRec(steps-1,idx+1,dp);
            right=right%MOD;
            return dp[steps][idx]=((left%MOD)+(stay%MOD)+(right%MOD))%MOD;
        }

        return dp[steps][idx]%MOD;

    }
};
