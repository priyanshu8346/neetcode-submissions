class Solution {
public:
    void heapify(vector<int>& nums,int current_parent, int last){
        int left_child = current_parent*2 + 1;
        int right_child = current_parent*2 + 2;
        if(left_child > last)return;
        else if(nums[current_parent] >= nums[left_child] &&   right_child <= last &&      nums[current_parent] >= nums[right_child]){
            return;
        }
        else{
            if(right_child <= last){
                if(nums[left_child] >= nums[right_child]){
                swap(nums[current_parent], nums[left_child]);
                current_parent = left_child;
                heapify(nums, current_parent, last);
                }
            else{
                swap(nums[current_parent], nums[right_child]);
                current_parent = right_child;
                heapify(nums, current_parent, last);
                }
            }
            else{
                if(nums[left_child] > nums[current_parent]){
                    swap(nums[current_parent], nums[left_child]);
                }
            }
            
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, i, n - 1);
        }

        int last = n - 1;

        while(last > 0) {

            swap(nums[0], nums[last]);

            last--;

            heapify(nums, 0, last);
        }
    return nums;
    }
};