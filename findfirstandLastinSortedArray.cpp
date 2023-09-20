class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size(),x=-1,y=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                x=i;
                break;
            }
        }
         for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                y=i;
                break;
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;

    }
};
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int first=-1,second;
        while(low<=high){
            int mid=(low+high)/2;
            int ans=nums[mid];
            if(ans==target&&(mid==0||nums[mid-1]!=target)){
                first=mid;
                break;
            }
            if(ans>=target) high=mid-1;
            else low=mid+1;
        }
        if(first==-1) return {-1,-1};
        low=first,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int ans=nums[mid];
            if(ans==target&&(mid==nums.size()-1||nums[mid+1]!=target)){
                second=mid;
                break;
            }
            if(ans>target) high=mid-1;
            else low=mid+1;
        }
        return {first,second};
    }
};
