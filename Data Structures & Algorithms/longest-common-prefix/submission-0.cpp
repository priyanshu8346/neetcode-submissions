class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = 0;
        while(true){
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() <= j || strs[i][j] != strs[0][j]){
                return strs[0].substr(0, j);
            }
        }
        j++;
        }
    }
};