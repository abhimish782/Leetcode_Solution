class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s1;
        for(auto it:nums){
            s1.insert(it);
        }
        int i=0;
        int ans=s1.size();
        for(auto it:s1){
            nums[i++]=it;
        }
        return ans;
    }
};
