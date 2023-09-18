class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>const& p1,pair<int,int>const& p2){
            if(p1.second==p2.second){
                return p1.first>p2.first;
            }
            return p1.second>p2.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int>m1;
        for(int i=0;i<mat.size();i++){
            int ctr=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    ctr++;
                }
            }
            m1[i]=ctr;
        }
        vector<pair<int,int>>pairs;
        for(auto it:m1){
            pairs.push_back(make_pair(it.first,it.second));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq(pairs.begin(),pairs.end());
        vector<int>ans;
        while(k){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return ans;
    }
};
