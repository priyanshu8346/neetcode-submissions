class Solution {
public:
    int check(vector<int>& hashMap, int k, int left, string& s) {
        int maxi = 0;
        int sum = 0;

        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, hashMap[i]);
            sum += hashMap[i];
        }

        while (sum - maxi > k) {
            hashMap[s[left] - 'A']--;
            left++;

            maxi = 0;
            sum = 0;

            for (int i = 0; i < 26; i++) {
                maxi = max(maxi, hashMap[i]);
                sum += hashMap[i];
            }
        }

        return left;
    }

    int characterReplacement(string s, int k) {
        vector<int> hashMap(26, 0);

        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            hashMap[s[right] - 'A']++;

            left = check(hashMap, k, left, s);

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};