class Solution {
public:
    struct mycmp{
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        return p1.second>=p2.second;
    }
};
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj=getAdjacency(times,n);
        vector<int>ans=dijksta(adj,n,k);
        int result=INT_MIN;
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=INT_MAX) result=max(result,ans[i]);
        }
        
        return result;
        
    }
    private:
    vector<vector<pair<int,int>>>getAdjacency(vector<vector<int>>edges,int n){
    vector<vector<pair<int,int>>>list(n+1);
    for (auto edge : edges) {
        list[edge[0]].push_back(make_pair(edge[1],edge[2]));
        //list[edge[1]].push_back(make_pair(edge[0],edge[2]));
    }
    return list;

}

vector<int>dijksta(vector<vector<pair<int,int>>>adj,int n,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp>pq;
    vector<bool>visited(n+1,false);
    vector<int>ans(n+1,INT_MAX);
    pq.push(make_pair(src,0));
    while(!pq.empty()){
        pair<int,int>curr=pq.top();
        visited[curr.first]=true;
        pq.pop();
        if(ans[curr.first]>curr.second) ans[curr.first]=curr.second;
        for(pair<int,int> neighbor:adj[curr.first]){
            neighbor.second+=curr.second;
            //cout<<neighbor.second<<" ";
            if(visited[neighbor.first]==false) pq.push(neighbor);
        }
    }
    for(int i=1;i<visited.size();i++){
        if(visited[i]==false) return {-1};
    }
    return ans;


}
};
