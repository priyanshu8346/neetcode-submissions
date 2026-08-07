class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const lookUp = new Map();
        for(let i = 0; i < nums.length; i++){
            let currentTarget = target - nums[i];
            let searched = (lookUp.get(currentTarget) || false);
            if(searched){
                for(const value of searched){
                    if (value !== i){
                        return [i, value].sort();
                    }
                }
                lookUp.get(nums[i]).push(i);
            }
            else{
                lookUp.set(nums[i], [i]);
            }
        }
    }
}
