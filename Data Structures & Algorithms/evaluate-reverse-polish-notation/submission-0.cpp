class Solution {
public:
    stack<int> st;
    void help(int top, int second_top, string token){
        if(token == "*")st.push(top*second_top);
        else if(token == "/")st.push(second_top/top);
        else if(token == "+")st.push(top+second_top);
        else st.push(second_top - top);
    }
    int evalRPN(vector<string>& tokens) {
        for(const string& token: tokens){
            if(token == "*" || token == "/" || token == "+" || token == "-"){
                int top = st.top();
                st.pop();
                int second_top = st.top();
                st.pop();
                help(top, second_top, token);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
