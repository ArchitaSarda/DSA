#include<iostream>
#include<stack>
#include<string>
using namespace std;

class ExpressionEvaluator {
    public:

        int calculate(int a, int b, char op) {
            switch (op) {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    return a / b;
                default:
                    return 0;
            }
        }

        int precedence(char op) {
            switch (op) {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                default:
                    return 0;
            }
        }
        
        int evaluate(string expression) {
            cout << "Expression is: " << expression << "\n";

            stack<char> operators;
            stack<int> operands;
            
            for(int i=0; i<expression.length(); i++) {
                if(expression[i] == ' ') 
                    continue;
                else if(isdigit(expression[i])) {
                    int val = 0;
                    while(i<expression.length() && isdigit(expression[i])) {
                        val = (val*10) + (expression[i] - '0');
                        i++;
                    }
                    operands.push(val);
                    i--;
                }
                else if(expression[i] == '(') {
                    operators.push(expression[i]);
                }
                else if(expression[i] == ')') {
                    while(operators.top() != '(' && !operators.empty()) {
                        int val2 = operands.top();
                        operands.pop();
                        int val1 = operands.top();
                        operands.pop();
                        char op = operators.top();
                        operators.pop();

                        operands.push(calculate(val1, val2, op));
                    }

                    if(!operators.empty()) {
                        operators.pop();
                    }
                }
                else {
                    while(!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                        int val2 = operands.top();
                        operands.pop();
                        int val1 = operands.top();
                        operands.pop();
                        char op = operators.top();
                        operators.pop();

                        operands.push(calculate(val1, val2, op));
                    }
                    operators.push(expression[i]);
                }
            }

            while(!operators.empty()) {
                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                operands.push(calculate(val1, val2, op));
            }

            return operands.top();

        };
};


int main() {
    // cout << "Enter expression to evaluate: " << "\n";
    // string expression;
    // getline(cin, expression);

    ExpressionEvaluator e;

    cout << e.evaluate("10 + 2 * 6") << "\n";
    cout << e.evaluate("100 * 2 + 12") << "\n";
    cout << e.evaluate("100 * 2 - 12") << "\n";
    cout << e.evaluate("100 * ( 2 + 12 )") << "\n";
    cout << e.evaluate("100 * ( 2 + 12 ) / 14") << "\n";

}


//https://www.geeksforgeeks.org/expression-evaluation/