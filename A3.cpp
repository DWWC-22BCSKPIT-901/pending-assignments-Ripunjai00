#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string s;
    stack<string> undoStack;

public:
    TextEditor() {}

    void append(string w) {
        undoStack.push("1 " + w);
        s += w;
    }

    void deleteChars(int k) {
        string deleted = s.substr(s.size() - k);
        undoStack.push("2 " + deleted);
        s = s.substr(0, s.size() - k);
    }

    void print(int k) {
        cout << s[k - 1] << endl;
    }

    void undo() {
        if (undoStack.empty()) return;

        string operation = undoStack.top();
        undoStack.pop();

        if (operation[0] == '1') {
            s = s.substr(0, s.size() - operation.substr(2).size());
        } else if (operation[0] == '2') { 
            s += operation.substr(2);
        }
    }
};

int main() {
    TextEditor editor;
    editor.append("abc");
    editor.print(3);   // c
    editor.deleteChars(3);
    editor.append("xy");
    editor.print(2);   // y
    editor.undo();
    editor.print(1);   // a
    return 0;
}
