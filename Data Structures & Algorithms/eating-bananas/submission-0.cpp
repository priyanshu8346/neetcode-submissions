class Solution {
public:

    bool eat(vector<int>& piles, int h, int mid){
        int current = 0;
        for(auto &it: piles){
            current+=ceil((double)it/mid);
            if(current > h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int possibleAnswer;
        int mid;
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while(start <= end){
        mid = (start + (end-start)/2);
        if(eat(piles, h, mid)){
            possibleAnswer = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
        }
        return possibleAnswer;
    }
};
