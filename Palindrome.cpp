class Solution {
public:
    bool isPalindrome(int x) {
        long long int s=0;
        int temp=x;
        while(x>0)
        {
        int p=x%10;
        s=s*10+p;
        x=x/10;
    }
        if(s==temp)
            return true;
        else
            return false;
    }
};
