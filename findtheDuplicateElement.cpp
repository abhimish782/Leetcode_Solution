class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>m1;
        for(int i:nums){
            m1[i]++;
        }
        for(auto it:m1){
            if(it.second!=1) return it.first;
        }
        return -1;//unreachable code
    }
};
