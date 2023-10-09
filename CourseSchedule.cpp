class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto edge:prerequisites){
            getAdjacencyList(adj,edge);
        }
        vector<int>indegree(numCourses,0);
        getIndegree(adj,numCourses,indegree);

        vector<int>ans;
	    //vector<int>indegree(V,0);
	    //getIndegree(adj,V,indegree);
	    queue<int>q;
	    for(int i=0;i<numCourses;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int curr=q.front();
	        q.pop();
	        ans.push_back(curr);
	        for(auto node:adj[curr]){
	            indegree[node]--;
	            if(indegree[node]==0) q.push(node);
	        }
	    }
        if(ans.size()!=numCourses) return false;
	    return true; 
	}
    void getAdjacencyList(vector<int>adj[],vector<int>edge){
        adj[edge[1]].push_back(edge[0]);
    }
    void getIndegree(vector<int>adj[],int v,vector<int>&indegree){
	    for(int i=0;i<v;i++){
	        for(auto edge:adj[i]){
	            indegree[edge]++;
	        }
	    }
    }
};
