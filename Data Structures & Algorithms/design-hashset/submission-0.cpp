class MyHashSet {

private:
    vector<vector<int>> hashSet;
public:
    MyHashSet() {
        hashSet.resize(1000);
    }
    
    void add(int key) {
        if(this->contains(key))return;
        int place = key%1000;
        hashSet[place].push_back(key);
    }
    
    void remove(int key) {
        int place = key%1000;
        for(auto it = hashSet[place].begin(); it != hashSet[place].end(); ++it){
            if (*it == key) {
    hashSet[place].erase(it);
    return;
}
        }
    }
    
    bool contains(int key) {
        int place = key%1000;
        for(auto &it: hashSet[place]){
            if(it == key)return true;
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