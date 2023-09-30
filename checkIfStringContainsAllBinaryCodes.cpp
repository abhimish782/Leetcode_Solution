class Solution {
public:
    bool hasAllCodes(string s, int k) {
       set<string>distinct;
       int ws=0,wend=0;
       string temp="";
       while(wend<s.length()){
           temp+=s[wend];
           if((wend-ws)+1==k){
               if(distinct.find(temp)==distinct.end()){
                   distinct.insert(temp);
               }
               temp.erase(0,1);
               ws++;
           }
           wend++;
       } 
       int ans=pow(2,k);
       cout<<ans;
       return distinct.size()==ans;
    }
};
