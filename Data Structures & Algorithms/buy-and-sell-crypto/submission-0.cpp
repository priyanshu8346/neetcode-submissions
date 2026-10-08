class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi= INT_MIN;
        int answer = 0;

        for(int i = prices.size()-1; i>=0; i--){
            maxi = max(maxi, prices[i]);
            answer = max(maxi-prices[i], answer);
        }
        return answer;
    }
};
