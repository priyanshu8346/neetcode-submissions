class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lookUp;
        int maxi = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            if(lookUp.find(s[i]) != lookUp.end()){
                while(s[left] != s[i]){
                    lookUp.erase(s[left]);
                    left++;
                }
                left++;
            }
            else{
                lookUp.insert(s[i]);
            }
            maxi = max(maxi, i-left+1);
        }
        return maxi;
    }
};
