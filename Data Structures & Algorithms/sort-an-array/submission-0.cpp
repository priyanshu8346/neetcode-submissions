class Solution {
public:
    void merge(vector<int> &nums, int start, int mid, int end){
        vector<int> temp;
        int second_start = mid + 1;
        int start_copy = start;
        int end_copy = end;
        while(start_copy <= mid && second_start <= end){
            if(nums[start_copy] <= nums[second_start]){
                temp.push_back(nums[start_copy++]);
            }
            else if(nums[start_copy] > nums[second_start]){
                temp.push_back(nums[second_start++]);
            }
        }
        if(second_start <= end_copy){
            for(int i = second_start; i <= end_copy; i++){
                temp.push_back(nums[i]);
            }
        }
        else if(start_copy <= mid){
            for(int i = start_copy; i <= mid; i++){
                temp.push_back(nums[i]);
            }
        }
        if(temp.size() == 0)return;
        int it = 0;
        for(int i = start; i <= end; i++){
            nums[i] = temp[it++];
        }
    }
    void sort(vector<int> &nums, int start, int end){
        int mid = start + (end - start)/2;
        if(end <= start){
            return ;
        }
        sort(nums, start, mid);
        sort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        int mid = size/2;
        sort(nums, 0, mid);
        sort(nums, mid + 1, size-1);
        merge(nums, 0, mid, size-1);
        return nums;
    }
};