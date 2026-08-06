class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if(s.length !== t.length){
            return false;
        }
        const difference = new Map();
        for(let i = 0; i < s.length; i++){
            difference.set(s[i], (difference.get(s[i]) || 0) + 1);
            difference.set(t[i], (difference.get(t[i]) || 0) - 1);
        }
        for(const [,value] of difference){
            if(value !== 0){
                return false;
            }
        }
        return true;
    }
}
