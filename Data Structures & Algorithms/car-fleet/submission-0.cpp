class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> timeNeeded;
        double time = 0;
        // timr calculation
        for(int i = 0; i < position.size(); i++){
            time = (double)(target - position[i])/speed[i];
            timeNeeded.push_back({position[i], time});
        }
        sort(timeNeeded.begin(), timeNeeded.end());
        int fleetCount = 0;
        double base = -1;
        for(int i = timeNeeded.size()-1; i >= 0; i-- ){
            if(timeNeeded[i].second > base){
                base = timeNeeded[i].second;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};
