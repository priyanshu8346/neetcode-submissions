class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hashMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int high = hashMap[key].size()-1;
        if(high == -1)return "";
        int low = 0;
        int mid;

        while(low <= high){
            mid = low + (high-low)/2;
            if(timestamp < hashMap[key][mid].first){
                high = mid - 1;
            }
            else if(timestamp > hashMap[key][mid].first){
                low = mid + 1;
            }
            else{
                return hashMap[key][mid].second;
            }
        }
        if(high < 0)return "";
        return hashMap[key][high].second;
    }
};
