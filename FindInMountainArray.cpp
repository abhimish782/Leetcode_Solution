/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0,n=mountainArr.length()-1,high=n;
        while(low<high){
            int mid=(low+high)/2;
            if(mountainArr.get(mid+1)>=mountainArr.get(mid)) low=mid+1;
            else high=mid;
        }
        int peak=low;
        int newLow=0;
        while(newLow<low){
            int mid=(newLow+low)/2;
            if(mountainArr.get(mid)>=target) low=mid;
            else newLow=mid+1;
        }
        if(mountainArr.get(newLow)==target) return newLow;
        newLow=peak+1;
        while(newLow<n){
            int mid=(newLow+n)/2;
            if(mountainArr.get(mid)<=target) n=mid;
            else newLow=mid+1;
        }
        if(mountainArr.get(newLow)==target) return newLow;
        return -1;
    }
};
