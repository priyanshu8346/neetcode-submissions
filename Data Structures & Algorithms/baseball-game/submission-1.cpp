class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        stack<int> st;
        int top;
        int second_top;
        for(auto& it: operations){
            if(it=="+"){
                top = st.top();
                st.pop();
                second_top = st.top();
                st.push(top);
                st.push(top+second_top);
                ans+=(top+second_top);
            }
            else if(it == "D"){
                int value = 2 * st.top();
                st.push(value);
                ans += value;
            }
            else if(it == "C"){
                ans-=st.top();
                st.pop();
            }
            else{
                st.push(stoi(it));
                ans+=stoi(it);
            }
        }
        return ans;
    }
};