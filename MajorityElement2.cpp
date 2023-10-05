class Solution1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        vector<int>ans;
        int check=floor(nums.size()/3);
        for(auto it:m){
            if(it.second>check){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
