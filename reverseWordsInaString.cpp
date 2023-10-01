class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<char>st;
        s+=' ';
        for(char i:s){
            if(i==' '){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+=' ';
            }
            else{
            st.push(i);
            }
        }
        ans.pop_back();
        return ans;
    }
};
