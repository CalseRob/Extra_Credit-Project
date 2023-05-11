#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

string balanceString(string s) {
    stack<char> st;
    string balanced = "";
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
            balanced += c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                if (c == ')') {
                    balanced = "(" + balanced;
                }
                else if (c == ']') {
                    balanced = "[" + balanced;
                }
                else if (c == '}') {
                    balanced = "{" + balanced;
                }
            }
            else {
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    if (c == ')') {
                        balanced += ")";
                    }
                    else if (c == ']') {
                        balanced += "]";
                    }
                    else if (c == '}') {
                        balanced += "}";
                    }
                    st.push(top);
                }
                else {
                    balanced += c;
                }
            }
        }
        else {
            balanced += c;
        }
    }
    while (!st.empty()) {
        char top = st.top();
        st.pop();
        if (top == '(') {
            balanced += ")";
        }
        else if (top == '[') {
            balanced += "]";
        }
        else if (top == '{') {
            balanced += "}";
        }
    }
    return balanced;
}

void checkBalance(Fl_Widget* w, void* data) {
    Fl_Input* input = (Fl_Input*)data;
    string s = input->value();
    string balanced = balanceString(s);
    if (isBalanced(balanced)) {
        Fl_Output* output = (Fl_Output*)w;
        output->value("The string is now balanced.");
    }
    else {
        Fl_Output* output = (Fl_Output*)w;
        output->value("The string cannot be balanced.");
    }

    // Process any pending events
    Fl::check();
}

int main() {
    Fl_Window window(300, 200, "Balancing Parentheses");

    Fl_Input int main() {
Fl_Window window(300, 200, "Balancing Parentheses");
Fl_Input input(100, 20, 100, 30, "String:");
Fl_Button button(100, 60, 100, 30, "Check");
Fl_Output output(100, 100, 150, 30);

button.callback(checkBalance, (void*)&input);

// Use case 1: Test a balanced string
input.value("(){}[]");
button.do_callback();
Fl::check();  // Process the output display

// Use case 2: Test an unbalanced string
input.value("(])");
button.do_callback();
Fl::check();  // Process the output display

// Use case 3: Attempt to balance an unbalanced string
input.value("(()))");
button.do_callback();
Fl::check();  // Process the output display

window.show();
return Fl::run();
    }
}
