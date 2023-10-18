class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<pair<int,int>>>dag(n+1);
        vector<int>inDegree(n+1,0);
        for(int i=0;i<relations.size();i++){
            dag[relations[i][0]].push_back(make_pair(relations[i][1],time[(relations[i][1])-1]));
            inDegree[relations[i][1]]++;
        }
        vector<pair<int,int>>currLevel;
        for(int i=1;i<=n;i++){
            if(inDegree[i]==0){
                currLevel.push_back(make_pair(i,time[i-1]));
            }
        }
        vector<int>waitingTime(n+1,0);
        for(int i=1;i<=n;i++){
            waitingTime[i]=time[i-1];
        }
        int minimumTime=0;
        unordered_set<int>completed;
        while(currLevel.size()!=0){
            vector<pair<int,int>>nextLevel;
            int maxAtLevel=INT_MIN;
            while(!currLevel.empty()){
                pair<int,int>currCourse=currLevel.back();
                cout<<currCourse.first<<"->";
                currLevel.pop_back();
                completed.insert(currCourse.first);
                maxAtLevel=max(waitingTime[currCourse.first],currCourse.second);
                for(auto neighbor:dag[currCourse.first]){
                    if(completed.find(neighbor.first)==completed.end()){
                        inDegree[neighbor.first]--;
                        waitingTime[neighbor.first]=max(neighbor.second+waitingTime[currCourse.first],waitingTime[neighbor.first]);
                        if(inDegree[neighbor.first]==0){
                            nextLevel.push_back(neighbor);
                        }
                    }
                }

            }
            minimumTime+=maxAtLevel;
            currLevel=move(nextLevel);
            cout<<endl;

        }
        return minimumTime;
    }
};
