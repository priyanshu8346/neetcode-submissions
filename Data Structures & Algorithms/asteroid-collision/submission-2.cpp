class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(const int item : asteroids) {
            bool alive = true;

            if(item > 0) {
                st.push(item);
                continue;
            }

            while(!st.empty() && st.top() > 0) {
                if(abs(item) > st.top()) {
                    st.pop();
                }
                else if(abs(item) < st.top()) {
                    alive = false;
                    break;
                }
                else {
                    st.pop();
                    alive = false;
                    break;
                }
            }

            if(alive) {
                st.push(item);
            }
        }

        vector<int> ans(st.size());

        for(int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};