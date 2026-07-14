#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string postfix;
    stack<int> st;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int value1 = st.top();
            st.pop();

            int value2 = st.top();
            st.pop();

            int ans;

            if (ch == '+')
                ans = value2 + value1;
            else if (ch == '-')
                ans = value2 - value1;
            else if (ch == '*')
                ans = value2 * value1;
            else if (ch == '/')
                ans = value2 / value1;
            else if (ch == '%')
                ans = value2 % value1;

            st.push(ans);
        }
    }

    cout << "Output = " << st.top();

    return 0;
}