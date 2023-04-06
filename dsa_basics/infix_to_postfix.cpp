#include<iostream>
#include<stack>
using namespace std;

class InfixPostfixConvertor {
    public:

        int precedence(char op) {
            switch(op) {
                case '^':
                    return 3;
                case '*':
                case '/':
                    return 2;
                case '+':
                case '-':
                    return 1;
                default:
                    return 0;
            }
        }
        string convert(string infixExp) {
            cout << "expression is: " << infixExp << "\n";
            string postfixExp;
            

            stack<char> operators;

            for(int i=0; i<infixExp.length(); i++) {
                if(infixExp[i] == ' ')
                    continue;
                else if(isdigit(infixExp[i])) {
                    while(i<infixExp.length() && isdigit(infixExp[i])) {
                        postfixExp = postfixExp + infixExp[i];
                        i++;
                    }
                    i--;
                    postfixExp += ' ';
                }
                else if((infixExp[i] >= 'a' && infixExp[i] <= 'z') || (infixExp[i] >= 'A' && infixExp[i] <= 'Z')) {
                    postfixExp += infixExp[i];
                    postfixExp += ' ';
                }
                else if(infixExp[i] == '(') {
                    operators.push(infixExp[i]);
                }
                else if(infixExp[i] == ')') {
                    while(
                        !operators.empty() && 
                        operators.top() != '('
                    ) {
                        postfixExp += operators.top();
                        postfixExp  += ' ';
                        operators.pop();
                    }
                    operators.pop();
                }
                else {
                    while(
                        !operators.empty() && 
                        precedence(operators.top()) >= precedence(infixExp[i])
                    ) {
                        postfixExp += operators.top();
                        postfixExp += ' ';
                        operators.pop();
                    }
                    operators.push(infixExp[i]);
                }
                
            }
            while(!operators.empty()) {
                    postfixExp += operators.top();
                    postfixExp += ' ';
                    operators.pop();
                }
            return postfixExp;
        }

};

int main() {
    InfixPostfixConvertor o;
    cout << o.convert("100 * ( 2 + 12 ) / 14") << "\n";
    cout << o.convert("100 + 2 * 4") << "\n";
    cout << o.convert("a+b*(c^d-e)^(f+g*h)-i") << "\n";
    cout << o.convert("a + b * c - d * e") << "\n";
    cout << o.convert("((a + b) * c - d) * e") << "\n";
    cout << o.convert("a * (b + c)") << "\n";
}

// expression is: 100 * ( 2 + 12 ) / 14
// 100 2 12 + * 14 / 
// expression is: 100 + 2 * 4
// 100 2 4 * + 
// expression is: a+b*(c^d-e)^(f+g*h)-i
// a b c d ^ e - f g h * + ^ * + i - 
// expression is: a + b * c - d * e
// a b c * + d e * - 
// expression is: ((a + b) * c - d) * e
// a b + c * d - e * 
// expression is: a * (b + c)
// a b c + * 