// backtracking
class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        //vector<string>allsubs;
        bool ans=false;
        string sub;
        search(t,ans,sub,0,s);
        return ans;
    }
    void search(string &t,bool &ans,string &sub,int i,string&s){
        if(i==t.length()){
            if(s==sub){
                ans=true;
                return;
            }
            return;
        }
        else{
            sub.push_back(t[i]);
            search(t,ans,sub,i+1,s);
            sub.pop_back();
            search(t,ans,sub,i+1,s);
        }
    }
};
// head recursive 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        return search(s.length(),t.length(),s,t);
        
    }
    bool search(int i,int j,string s, string t){
        if(i==0) return true;
        if(j==0) return false;

        if(s[i-1]==t[j-1]){
            return search(i-1,j-1,s,t);
        }
        else{
            return search(i,j-1,s,t);
        }
    }
};
