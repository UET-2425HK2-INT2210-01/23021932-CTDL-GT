#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;

bool isValid(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    
// bài này em thêm n vào đầu là số chuỗi cần xét, không có thì em khôn biết làm như nào ạ :(((

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    while (n--) {
        string s;
        getline(cin, s);

        if (isValid(s))
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
}
