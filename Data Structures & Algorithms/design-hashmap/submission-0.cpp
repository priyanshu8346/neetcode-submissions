class MyHashMap {
public:
    struct entry{
        int key;
        int value;
    };
    vector<vector<entry>> HashMap;

    MyHashMap() {
        HashMap.resize(1000);
    }
    
    void put(int key, int value) {
        int bucket = key%1000;
        for(auto& it: HashMap[bucket]){
            if(it.key == key){
                it.value = value;
                return;
            }
        }
        HashMap[bucket].push_back({key, value});
    }
    
    int get(int key) {
        int bucket = key%1000;
        for(const auto& it: HashMap[bucket]){
            if(it.key == key)return it.value;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = key%1000;
         for(auto it = HashMap[bucket].begin(); it != HashMap[bucket].end(); ++it) {
            if(it->key == key){
            HashMap[bucket].erase(it);
            return;
        }
    }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */