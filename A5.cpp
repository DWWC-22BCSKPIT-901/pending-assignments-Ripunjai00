#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib> 
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();

            if (token == "+") stk.push(a + b);
            else if (token == "-") stk.push(a - b);
            else if (token == "*") stk.push(a * b);
            else if (token == "/") stk.push(a / b);
        } else {
            stk.push(atoi(token.c_str()));
        }
    }
    return stk.top();
}

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    cout << evalRPN(tokens) << endl; 
    
    tokens = {"4","13","5","/","+"};
    cout << evalRPN(tokens) << endl; 

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens) << endl; 
    
    return 0;
}
