class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> nearestSmallest(heights.size(), {0,0});
        stack<pair<int, int>> st;
        // first if left and second is right
        for(int i =0; i < heights.size(); i++){
            while(true){
                if(st.empty()){
                st.push({heights[i], i});
                nearestSmallest[i].first = -1;
                break;
                }
                if(st.top().first >= heights[i]){
                    st.pop();
                }
                else{
                nearestSmallest[i].first = st.top().second;
                st.push({heights[i], i});
                break;
                }
            }
        }
        while(!st.empty())
        st.pop();

        for(int i =heights.size()-1; i>=0; i--){
            while(true){
                if(st.empty()){
                st.push({heights[i], i});
                nearestSmallest[i].second = heights.size();
                break;
                }
                if(st.top().first >= heights[i]){
                    st.pop();
                }
                else{
                nearestSmallest[i].second = st.top().second;
                st.push({heights[i], i});
                break;
                }
            }
        }
        int current_max = 0;

        for(int i = 0; i < nearestSmallest.size(); i++){
            current_max = max(current_max, (heights[i]*(nearestSmallest[i].second-nearestSmallest[i].first-1)));
        }
        return current_max;
    }
};
