class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>bitvector(nums.size(),true);
        vector<int>perm;
        vector<vector<int>>all;
        search(nums,bitvector,perm,all);
        return all;
    }
    void search(vector<int>&nums,vector<bool>&bitvector,vector<int>&perm,vector<vector<int>>&all){
        if(perm.size()==nums.size()) all.push_back(perm);
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
