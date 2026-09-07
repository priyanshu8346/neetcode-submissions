class MinStack {
public:
stack<pair<int, int>> st;
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else
        st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
