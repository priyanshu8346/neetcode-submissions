class Solution {
public:
    void sortColors(vector<int>& nums) {

        int current = 0;
        int current_left = 0;
        int current_right = nums.size() - 1;

        while(current <= current_right) {

            if(nums[current] == 0) {
                swap(nums[current], nums[current_left]);
                current_left++;
                current++;
            }

            else if(nums[current] == 1) {
                current++;
            }

            else {
                swap(nums[current], nums[current_right]);
                current_right--;
            }
        }
    }
};