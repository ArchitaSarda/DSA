#include<iostream>
#include<string>
#include<stack>
using namespace std;

string isExpressionBalanced(string &str, int size) {
    if(size <= 1) { return "Invalid expression"; };
    
    stack<char> s;
    for(int i=0; i<size; i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        }
        if(str[i] == '}') {
            if(s.empty() || s.top() != '{') {
                return "Invalid expression"; 
            } else {
                s.pop();
            }
        }
        if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {
                return "Invalid expression"; 
            } else {
                s.pop();
            }
        }
        if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                return "Invalid expression"; 
            } else {
                s.pop();
            }
        }
        
    }
    string r = s.empty() ? "Valid expression" : "Invalid expression";
    return r;

};

int main() {
    // string str;
    // cout << "enter a string: " << "\n";
    // getline(cin,str);
    string str = "}{";
    cout << "Expression is: " << str << "\n";
    cout << isExpressionBalanced(str, str.length()) << "\n";
}
