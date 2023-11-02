//O(n*2^n) time and O(2^n) space
class Solution1 {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int>subset;// subset of indices easy to validate
        search(powerSet,subset,0,nums);
        int ans=INT_MIN;
        for(vector<int>&sub:powerSet){
            if(isValid(sub,nums.size())){
                ans=max(ans,findVal(sub,nums));
            }
        }
        return ans;
    }
    void search(vector<vector<int>>&ps,vector<int>&sub,int i,vector<int>&nums){
        if(i==nums.size()){
            ps.push_back(sub);
        }
        else{
            search(ps,sub,i+1,nums);// without
            sub.push_back(i);
            search(ps,sub,i+1,nums);
            sub.pop_back();
        }
    }
    bool isValid(vector<int>sub,int n){
        if(!sub.size()) return true;
        for(int i=1;i<sub.size();i++){
            if((abs(sub[i-1]-sub[i])==1)||(abs(sub.back()-sub.front())==n-1)) return false;
        }
        return true;
    }
    int findVal(vector<int>sub,vector<int>&nums){
        int ans=0;
        for(int i:sub){
            ans+=nums[i];
        }
        return ans;
    }
};
//O(2^n) time and O(1) space interleaved on the fly
class Solution2 {
public:
    int rob(vector<int>& nums) {
        //vector<vector<int>> powerSet;
        vector<int>subset;// subset of indices easy to validate
        int ans=INT_MIN;
        search(ans,subset,0,nums);
        return ans;
    }
    void search(int& ans,vector<int>&sub,int i,vector<int>&nums){
        if(i==nums.size()){
            if(isValid(sub,nums.size())){
                ans=max(ans,findVal(sub,nums));
            }
        }
        else{
            search(ans,sub,i+1,nums);// without
            sub.push_back(i);
            search(ans,sub,i+1,nums);
            sub.pop_back();
        }
    }
    bool isValid(vector<int>sub,int n){
        if(!sub.size()) return true;
        for(int i=1;i<sub.size();i++){
            if((abs(sub[i-1]-sub[i])==1)||(abs(sub.back()-sub.front())==n-1)) return false;
        }
        return true;
    }
    int findVal(vector<int>sub,vector<int>&nums){
        int ans=0;
        for(int i:sub){
            ans+=nums[i];
        }
        return ans;
    }
};
//O(1.62^n) time and O(1) space 
// branch pruned solution to reduce validate function
class Solution3{
public:
    int rob(vector<int>& nums) {
        //vector<vector<int>> powerSet;
        vector<int>subset;// subset of indices easy to validate
        int ans=INT_MIN;
        search(ans,subset,0,nums);
        return ans;
    }
    void search(int& ans,vector<int>&sub,int i,vector<int>&nums){
        if(i>=nums.size()){
            ans=max(ans,findVal(sub,nums));
        }
        else{
            search(ans,sub,i+1,nums);// without
            if(sub.size()&&(abs(sub.front()-i)==nums.size()-1)) return;
            else{
                sub.push_back(i);
                search(ans,sub,i+2,nums);
                sub.pop_back();
            }
        }
    }
    int findVal(vector<int>sub,vector<int>&nums){
        int ans=0;
        for(int i:sub){
            ans+=nums[i];
        }
        return ans;
    }
};
// O(2^n) time implementation of head recurrence
class Solution4{
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(f1(0,nums,nums.size()-1),f1(1,nums,nums.size()));
    }
    int f1(int i,vector<int>&nums,int n){
        if(i>=n) return 0;

        int without=f1(i+1,nums,n);
        int with=nums[i]+f1(i+2,nums,n);
        return max(with,without);
    }
};

class Solution{
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int>tbl1;
        unordered_map<int,int>tbl2;
        if(nums.size()==1) return nums[0];
        return max(f1(0,nums,nums.size()-1,tbl1),f1(1,nums,nums.size(),tbl2));
    }
    int f1(int i,vector<int>&nums,int n,unordered_map<int,int>&tbl){
        if(i>=n) return 0;
        else if(tbl.find(i)!=tbl.end()) return tbl[i];
        else{

        int without=f1(i+1,nums,n,tbl);
        int with=nums[i]+f1(i+2,nums,n,tbl);
        return tbl[i]=max(with,without);
        }
    }
};


