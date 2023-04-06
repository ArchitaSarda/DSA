#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverse(string &str, int size) {
    stack<char> s;
    for(int i=0;i<size;i++) {
        s.push(str[i]);
    }
    for(int i=0;i<size;i++) {
        str[i] = s.top();
        s.pop();
    }
}

int main() {
    string str;
    cout << "enter a string: " << "\n";
    getline(cin,str);
    reverse(str, str.length());
    cout << str << "\n";
    return 0;

}