class Solution {
public:
    bool isbalance(char y,char x){
        return ((x=='('&&y==')')||(x=='{'&&y=='}')||(x=='['&&y==']'));
    }
    bool isValid(string s) {
        stack<char>st;
        for(char i:s){
            if(i=='('||i=='{'||i=='['){
                st.push(i);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(isbalance(i,st.top())==false){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return(st.empty()==true);

        
    }
};
