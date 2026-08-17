class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current_majority = nums[0];
        int current_count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == current_majority)current_count++;
            else current_count--;
            if(current_count < 0){
                current_majority = nums[i];
                current_count = 1;

            }
        }
        return current_majority;
    }
};