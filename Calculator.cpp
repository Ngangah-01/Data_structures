#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return -1;
    }
}
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (char c : infix) {

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
            postfix += c;
        }
        else if (isOperator(c))
            {
            if (s.empty() || s.top() == '(') {
                s.push(c);
            }
            else {
                while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
