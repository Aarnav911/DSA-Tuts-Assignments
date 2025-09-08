#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (char c : expr) {
        if (isdigit(c)) {
            st.push(c - '0');  
        } 
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < val2; i++) result *= val1;
                    st.push(result);
                    break;
                }
            }
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    cout << "Evaluated result: " << evaluatePostfix(expr) << endl;
    return 0;
}
