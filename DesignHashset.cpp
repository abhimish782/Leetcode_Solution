class MyHashSet {
public:
    vector<int>hashSet;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)==false)
            hashSet.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<hashSet.size();i++){
            if(hashSet[i]==key){
                hashSet[i]=-1;
            }
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<hashSet.size();i++){
            if(hashSet[i]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
