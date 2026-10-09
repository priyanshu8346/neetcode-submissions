class Solution {
public:

    bool check(vector<int> &targetStringFreq,vector<int> &refStringFreq){
        for(int i = 0; i < 26; i++){
            if(targetStringFreq[i] != refStringFreq[i])return false;
        }
        return true;
    }

    void clearArray(vector<int> &targetStringFreq){
        for(auto& it: targetStringFreq){
            it = 0;
        }
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> refStringFreq(26, 0);
        vector<int> targetStringFreq(26, 0);
        for(auto& it:s1){
            refStringFreq[it-'a']++;
        }
        int currentWindowSize = 0;
        int left = 0;
        for(int right=0; right <s2.size(); right++){
            if(refStringFreq[s2[right]-'a']==0){
                clearArray(targetStringFreq);
                currentWindowSize = 0;
                left = right + 1;     
            }
            else{
                targetStringFreq[s2[right]-'a']++;
                currentWindowSize++;
                while(currentWindowSize> s1.size()){
                    targetStringFreq[s2[left]-'a']--;
                    left++;
                    currentWindowSize--;
                }
                if(currentWindowSize == s1.size() && check(targetStringFreq, refStringFreq)){
                    return true;
                }
            }

        }
        return false;
    }
};
