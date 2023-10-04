class MyHashMap {
public:
    vector<int>hashMap;
    MyHashMap() {
        for(int i=0;i<1000000;i++){
            hashMap.push_back(-1);
        }
    }
    
    void put(int key, int value) {
        if(hashMap[key]==-1){
            hashMap[key]=value;
        }
        else{
            hashMap[key]=value;
        }
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
