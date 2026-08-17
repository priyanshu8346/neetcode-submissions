class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        int count = 0;

        while(start <= end){
            if(nums[start] == val){
                swap(nums[start], nums[end--]);
                count++;
                if(nums[start] != val)start++;
            }
            else{
                start++;
            }
        }
        return nums.size() - count;
    }
};