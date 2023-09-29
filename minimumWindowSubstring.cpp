class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1;
        for(int i=0;i<t.size();i++){
            m1[t[i]]++;
        }
        int req=m1.size(),des=0;
        int ans[3]={-1,0,0};
        int wstart=0,wend=0;
        unordered_map<char,int>window;
        while(wend<s.length()){
            char c=s[wend];
            window[c]++;
            if(m1.find(c)!=m1.end() && m1[c]==window[c]){
                des++;
            }
            while(wstart<=wend&&des==req){
                char d=s[wstart];
                if(ans[0]==-1||(wend-wstart+1)<ans[0]){
                    ans[0]=wend-wstart+1;
                    ans[1]=wstart;
                    ans[2]=wend;
                }
                window[d]--;
                if(m1[d]>0 && window[d]<m1[d]){
                    des--;
                }
                wstart++;
            }
            wend++;
        }
        string res="";
        if(ans[0]==-1){
            return res;
        }
        for(int i=ans[1];i<=ans[2];i++){
            res+=s[i];
        }
        return res;
        
    }
};
