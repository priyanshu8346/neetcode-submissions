class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> ans(size, 0);
        int current = size - 1;
        for(int i = current; i >= 0; i--){
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                }
                else{
                    ans[i] = st.top() - i;
                }
            }
            st.push(i);
        }
        return ans;
    }
};
