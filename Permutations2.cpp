class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>bitvector(nums.size(),true);
        vector<int>perm;
        set<vector<int>>all;
        search(nums,bitvector,perm,all);
        vector<vector<int>>ans;
        for(auto it:all){
            ans.push_back(it);
        }
        return ans;
    }
    void search(vector<int>&nums,vector<bool>&bitvector,vector<int>&perm,set<vector<int>>&all){
        if(perm.size()==nums.size()) all.insert(perm);
        else{
            for(int i=0;i<nums.size();i++){
                if(bitvector[i]){
                    bitvector[i]=false;
                    perm.push_back(nums[i]);
                    search(nums,bitvector,perm,all);
                    perm.pop_back();
                    bitvector[i]=true;
                }
            }
        }
    }
};
