// BackTracking solution O(n*2^n) time and O(2^n) space 
/*void search(vector<vector<int>>&ps,vector<int>&sub,int i,int n){
    if(i==n){
        ps.push_back(sub);
        return;
    }
    
    search(ps,sub,i+1,n); // without case
    sub.push_back(i);
    search(ps,sub,i+1,n);
    sub.pop_back();
}
bool IsValid(vector<int>sub,vector<int>weight,int cap){
    int sum=0;
    for(int i:sub){
        sum+=weight[i];
        if(sum>cap) return false;
    }
    return true;
}
int findVal(vector<int>sub,vector<int>val){
    int ans=0;
    for(int i:sub){
        ans+=val[i];
    }
    return ans;
}

int Solution1::solve(vector<int> &value, vector<int> &weight, int capacity) {
    vector<vector<int>>ps;
    vector<int>sub;
    search(ps,sub,0,value.size());
    int ans=0;
    for(vector<int> ss: ps){
        if(IsValid(ss,weight,capacity)){
            ans=max(ans,findVal(ss,value));
        }
    }
    return ans;
}*/

// Backtracking interleaved with exhaustive search O(n*2^n) time and O(1) space
/*bool IsValid(vector<int>sub,vector<int>weight,int cap){
    int sum=0;
    for(int i:sub){
        sum+=weight[i];
        if(sum>cap) return false;
    }
    return true;
}
int findVal(vector<int>sub,vector<int>val){
    int ans=0;
    for(int i:sub){
        ans+=val[i];
    }
    return ans;
}
void search(int&ans,vector<int>&sub,int i,vector<int>&val,vector<int>&weight,int capacity){
    if(i==val.size()){
        if(IsValid(sub,weight,capacity)){
            ans=max(ans,findVal(sub,val));
        }
        return;
    }
    
    search(ans,sub,i+1,val,weight,capacity); // without case
    sub.push_back(i);
    search(ans,sub,i+1,val,weight,capacity);
    sub.pop_back();
}


int Solution2::solve(vector<int> &value, vector<int> &weight, int capacity) {
    //vector<vector<int>>ps;
    vector<int>sub;
    int ans=0;
    search(ans,sub,0,value,weight,capacity);
    return ans;
}*/

// BranchPruned BackTracking solution
/*int findVal(vector<int>sub,vector<int>val){
    int ans=0;
    for(int i:sub){
        ans+=val[i];
    }
    return ans;
}
void search(int&ans,vector<int>&sub,int i,vector<int>&val,vector<int>&weight,int capacity){
    if(i==val.size()){
        ans=max(ans,findVal(sub,val));
        return;
    }
    
    search(ans,sub,i+1,val,weight,capacity); // without case
    if(weight[i]<=capacity){
        sub.push_back(i);
        search(ans,sub,i+1,val,weight,capacity-weight[i]);
        sub.pop_back();
        capacity+=weight[i];
        
    }
}


int Solution3::solve(vector<int> &value, vector<int> &weight, int capacity) {
    //vector<vector<int>>ps;
    vector<int>sub;
    int ans=0;
    search(ans,sub,0,value,weight,capacity);
    return ans;
}*/

// O(2^n) head recursive solution tle
// f1(val,weight)=max(f1(val,weight),val[i]+f1(val,weight))
/*int f1(int i,vector<int>&val,vector<int>&weight,int capacity){
    if(i==val.size()) return 0;
    int without=f1(i+1,val,weight,capacity);
    int with=0;
    if(weight[i]<=capacity){
        with=val[i]+f1(i+1,val,weight,capacity-weight[i]);
    }
    return max(without,with);
}

int Solution4::solve(vector<int> &value, vector<int> &weight, int capacity) {
    return f1(0,value,weight,capacity);
}
*/
// memoized solution using hash table 
// O(n) time and O(nc) space where c is capacity
/*int f1(int i,vector<int>&val,vector<int>&weight,int capacity,map<vector<int>,int>&tbl){
    vector<int>key={i,capacity};
    if(i==val.size()) return tbl[key]=0;
    if(tbl.find(key)!=tbl.end()) return tbl[key]; //cache hit;
    else{       // cache miss
        int without=f1(i+1,val,weight,capacity,tbl);
        int with=0;
        if(weight[i]<=capacity){
            with=val[i]+f1(i+1,val,weight,capacity-weight[i],tbl);
        }
        return tbl[key]=max(without,with);
    }
}

int Solution5::solve(vector<int> &value, vector<int> &weight, int capacity) {
    map<vector<int>,int>tbl;
    return f1(0,value,weight,capacity,tbl);
}*/
// memoization using 2-D vector
int f1(int i,vector<int>&val,vector<int>&weight,int capacity,vector<vector<int>>&tbl){
    if(i==val.size()) return tbl[i][capacity]=0;
    if(tbl[i][capacity]!=-1) return tbl[i][capacity];
    else{
        int without=f1(i+1,val,weight,capacity,tbl);
        int with=0;
        if(weight[i]<=capacity){
            with=val[i]+f1(i+1,val,weight,capacity-weight[i],tbl);
        }
        return tbl[i][capacity]=max(without,with);
    }
}

int Solution6::solve(vector<int> &value, vector<int> &weight, int capacity) {
    vector<vector<int>>tbl(value.size()+1,vector<int>(capacity+1,-1));
    return f1(0,value,weight,capacity,tbl);
}
