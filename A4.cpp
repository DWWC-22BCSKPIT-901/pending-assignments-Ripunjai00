#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> stack1, stack2;

public:
    MyQueue() {}

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int val = stack2.top();
        stack2.pop();
        return val;
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl; 
    cout << queue.pop() << endl; 
    cout << queue.empty() << endl; 
    return 0;
}
