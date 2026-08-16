class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> freq;
        for(int i = 0; i < n; i++){
            vector<int> temp(26, 0);
            string temp_s="";
            for(char c: strs[i]){
                temp[c - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                temp_s+=('#' + to_string(temp[j]));
            }
            freq[temp_s].push_back(strs[i]);
        }
        for(auto &it: freq){
            ans.push_back(it.second);
        }
        return ans;
    }
};