class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();

        int start = 0;
        int end = row_size * col_size - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            int current_row = mid / col_size;
            int current_col = mid % col_size;

            int current_element = matrix[current_row][current_col];

            if(current_element < target) {
                start = mid + 1;
            }
            else if(current_element > target) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};