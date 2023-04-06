#include<iostream>
#include<stack>
using namespace std;

class PostfixExpressionEvaluator {

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

        int evaluate(string expression) {
            cout << "The expression is: " << expression << "\n";

            stack<int> operands;

            for(int i=0; i<expression.length(); i++) {
                if(expression[i] == ' ')
                    continue;
                else if(isdigit(expression[i])) {
                    int val = 0;
                    while(i < expression.length() && isdigit(expression[i])) {
                        val = val*10 + (expression[i] - '0');
                        i++;
                    }
                    i--;
                    operands.push(val);
                }
                else {
                    int val2 = operands.top();
                    operands.pop();

                    int val1 = operands.top();
                    operands.pop();

                    operands.push(calculate(val1, val2, expression[i]));
                }
            }

            return operands.top();
        }

};

int main() {
    PostfixExpressionEvaluator e;
    cout << e.evaluate("100 2 * 12 -") << "\n";
    cout << e.evaluate("100 2 * 12 +") << "\n";
    cout << e.evaluate("2 3 * 5 4 * + 9 -") << "\n";
    cout << e.evaluate("100 200 + 2 / 5 * 7 +") << "\n";
}