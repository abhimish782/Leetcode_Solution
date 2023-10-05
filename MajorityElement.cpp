class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m,f=1;
        m=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==m){
                f++;
            }
            else {
                f--;
            }
            if(f==0){
                m=nums[i+1];
            }
        }
        int fin=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                fin++;
            }
        }
        if(fin>nums.size()/2){
            return m;
        }
        return -1;
    }
};
