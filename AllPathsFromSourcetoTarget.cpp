// backtracking solution
class Solution1 {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        path.push_back(0);
        search(0,path,graph);
        return ans;
    }
    void search(int node,vector<int>&path,vector<vector<int>>&graph){
        if(node==graph.size()-1){
            ans.push_back(path);
            return;
        }
        else{
            for(int neighbor:graph[node]){
                path.push_back(neighbor);
                search(neighbor,path,graph);
                path.pop_back();
            }
        }
    }
};

// hybrid of backtracking and head recusive solution 
class Solution2 {
public:
    //vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        path.push_back(0);
        return search(0,path,graph);
        
    }
    vector<vector<int>>search(int node,vector<int>&path,vector<vector<int>>&graph){
        if(node==graph.size()-1){
            return {{path}};
        }
        else{
            vector<vector<int>> result;
            for(int neighbor:graph[node]){
                path.push_back(neighbor);
                auto temp=search(neighbor,path,graph);
                result.insert(result.end(),temp.begin(),temp.end());
                path.pop_back();
            }
            return result;
        }
    }
};
// head recursive solution 
class Solution3 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        return head_reccur(0,graph);
        
    }
    vector<vector<int>> head_reccur(int node,vector<vector<int>>&graph){
        if(node==graph.size()-1){
            return {{node}};
        }
        vector<vector<int>>result;
        for(int neighbor:graph[node]){
            auto temp=head_reccur(neighbor,graph);
            for(auto path:temp){
                path.insert(path.begin(),node);  // prepending the node 
                result.push_back(path);
            }
        }
        return result;
    }
};
