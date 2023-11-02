// O(n*2^n) time and O(2^n) space backtracking solution
class Solution1{
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> subset; // a subset of indices not values so that validation is easy
        int ans=INT_MIN;
        search(powerSet,subset,0,nums);
        for(vector<int>& sub:powerSet){
            if(isValid(sub)){
                ans=max(ans,findVal(sub,nums));
            }
        }
        return ans;
    }
    void search(vector<vector<int>>&powerSet,vector<int>&subset,int i,vector<int>&nums){
        if(i==nums.size()){
            powerSet.push_back(subset);
        }else{
        search(powerSet,subset,i+1,nums);// without case
        subset.push_back(i);
        search(powerSet,subset,i+1,nums); // with case
        subset.pop_back();
        }
    }
    bool isValid(vector<int>&sub){
        if(!sub.size()) return true;
        for(int i=1;i<sub.size();i++){
            if(abs(sub[i-1]-sub[i])==1) return false;
        }
        return true;
    }
    int findVal(vector<int>&sub,vector<int>&nums){
        int ans=0;
        for(int i:sub){
            ans+=nums[i];
        }
        return ans;
    }
};

// O(n*2^n) time and O(1) extra space
// interleaving the powerset and validation with its generation
class Solution2{
public:
    int rob(vector<int>& nums) {
        // vector<vector<int>> powerSet; // validation on the fly
        vector<int> subset; // a subset of indices not values so that validation is easy
        int ans=INT_MIN; // also findding the maximum on the fly
        search(ans,subset,0,nums);
        return ans;
    }
    void search(int &ans,vector<int>&subset,int i,vector<int>&nums){
        if(i==nums.size()){
            if(isValid(subset)){
            ans=max(ans,findVal(subset,nums));
            }
        }else{
        search(ans,subset,i+1,nums);// without case
        subset.push_back(i);
        search(ans,subset,i+1,nums); // with case
        subset.pop_back();
        }
    }
    // O(n) time validation
    bool isValid(vector<int>&sub){
        if(!sub.size()) return true;
        for(int i=1;i<sub.size();i++){
            if(abs(sub[i-1]-sub[i])==1) return false;
        }
        return true;
    }
    int findVal(vector<int>&sub,vector<int>&nums){
        int ans=0;
        for(int i:sub){
            ans+=nums[i];
        }
        return ans;
    }
};
// O(1.62^n) time solution 
class Solution3{
public:
    int rob(vector<int>& nums) {
        vector<int> subset; // a subset of indices not values so that validation is easy
        int ans=INT_MIN;
        search(ans,subset,0,nums);
        return ans;
    }
    void search(int &ans,vector<int>&subset,int i,vector<int>&nums){
        if(i>=nums.size()){ // i could go out of bound
            ans=max(ans,findVal(subset,nums));
        }else{
        search(ans,subset,i+1,nums);// without case
        subset.push_back(i);
        // if we pick an element we need to ignore its neighbor so that we 
        // save validation the subsets generated are already valid
        search(ans,subset,i+2,nums); // with case 
        subset.pop_back();
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
// backtracking converted to naive head recursive 
// the recurrence looks like
// f1(i,nums)=max(f1(i+1,nums),nums[i]+f1(i+2,nums))
//O(2^n) time and O(1) space
class Solution4{
public:
    int rob(vector<int>& nums) {
        return f1(0,nums);
    }
    int f1(int i,vector<int>&nums){
        if(i>=nums.size()) return 0;
        int without=f1(i+1,nums);
        int with=nums[i]+f1(i+2,nums);
        return max(with,without);
    }
};
// memoization of head recurrence using hash table to avoid overlapping subpro
// O(n) time bcz there are only n distint problems to solve 
//O(n) space map space 
class Solution5{
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int>tbl;
        return f1(0,nums,tbl);
    }
    int f1(int i,vector<int>&nums,unordered_map<int,int>&tbl){
        if(i>=nums.size()) return tbl[i]=0;
        else if(tbl.find(i)!=tbl.end()) return tbl[i];
        else{
        int without=f1(i+1,nums,tbl);
        int with=nums[i]+f1(i+2,nums,tbl);
        return tbl[i]=max(with,without);
        }
    }
};
// memoization using array 
// O(n) time and O(n) space
class Solution{
public:
    int rob(vector<int>& nums) {
        vector<int>tbl(nums.size()+1,-1);
        return f1(0,nums,tbl);
    }
    int f1(int i,vector<int>&nums,vector<int>&tbl){
        if(i>=nums.size()) return 0;
        else if(tbl[i]!=-1) return tbl[i];
        else{
        int without=f1(i+1,nums,tbl);
        int with=nums[i]+f1(i+2,nums,tbl);
        return tbl[i]=max(with,without);
        }
    }
};

class Solution{
public:
    int rob(vector<int>& nums) {
        vector<int>tbl(nums.size()+1,-1);
        
    }
    int f1(int i,vector<int>&nums,vector<int>&tbl){
        if(i>=nums.size()) return 0;
        else if(tbl[i]!=-1) return tbl[i];
        else{
        int without=f1(i+1,nums,tbl);
        int with=nums[i]+f1(i+2,nums,tbl);
        return tbl[i]=max(with,without);
        }
    }
};
