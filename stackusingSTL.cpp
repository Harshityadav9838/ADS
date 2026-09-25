// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     stack<int> s;

//     // Pushing elements onto the stack
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);

//     cout << "Top element: " << s.top() << endl; 

//     // Popping an element from the stack
//     s.pop();
//     cout << "Top element after pop: " << s.top() << endl; 

//     //size of the stack
//     cout << "Size of stack: " << s.size() << endl;

//     // Checking if the stack is empty
//     if (s.empty()) {
//         cout << "Stack is empty." << endl;
//     } else {
//         cout << "Stack is not empty." << endl; 
//     }
    
//     //Display all elements
//     cout << "stack elements:";
//     while (!s.empty()) {
//         cout << " " << s.top();
//         s.pop();
//     }
//     cout << endl;

//     return 0;
// }
#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        // Operand
        if (isalnum(ch)) {
            postfix += ch;
        }
        // Left parenthesis
        else if (ch == '(') {
            st.push(ch);
        }
        // Right parenthesis
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // Operator
        else {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}