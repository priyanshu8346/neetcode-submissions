class Solution {
public:
    void help(int top, int second_top, const string& token, stack<int>& st){
        if(token == "*")st.push(top*second_top);
        else if(token == "/")st.push(second_top/top);
        else if(token == "+")st.push(top+second_top);
        else st.push(second_top - top);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& token: tokens){
            if(token == "*" || token == "/" || token == "+" || token == "-"){
                int top = st.top();
                st.pop();
                int second_top = st.top();
                st.pop();
                help(top, second_top, token, st);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
