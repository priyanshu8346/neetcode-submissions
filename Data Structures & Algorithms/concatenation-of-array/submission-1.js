class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    getConcatenation(nums) {
        const ans = []
        let j = 2;
        while(j !== 0){
        for(let i = 0; i < nums.length; i++){
            ans.push(nums[i]);
        }
        j--;
        }
        return ans;
    }
}
