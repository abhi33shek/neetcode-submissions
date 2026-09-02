class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for (const string& token : tokens) {
            if (token == "+") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                st.push(a + b);
            } else if (token == "-") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                st.push(a - b);
            } else if (token == "*") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                st.push(a * b);
            } else if (token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                st.push(a / b); 
            } else {
                st.push(stoll(token));
            }
        }
        
        return (int)st.top();
    }
};