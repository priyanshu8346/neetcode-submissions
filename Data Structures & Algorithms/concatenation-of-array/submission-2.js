class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    getConcatenation(nums) {
        const ans = []
        let repeataion = 2;
        while(repeataion !== 0){
        for(let i = 0; i < nums.length; i++){
            ans.push(nums[i]);
        }
        repeataion--;
        }
        return ans;
    }
}
