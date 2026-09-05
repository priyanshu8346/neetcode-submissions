class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq_map;

        int max_frequency = 0;

        for(const int i : nums) {
            freq_map[i]++;
            max_frequency = max(max_frequency, freq_map[i]);
        }

        vector<vector<int>> bucket(max_frequency + 1);

        for(auto it : freq_map) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        for(int i = max_frequency; i >= 1; i--) {

            for(auto it : bucket[i]) {

                if(k == 0)
                    return ans;

                ans.push_back(it);
                k--;
            }
        }

        return ans;
    }
};