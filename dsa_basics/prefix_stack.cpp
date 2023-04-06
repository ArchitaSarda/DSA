#include<iostream>
#include<stack>
using namespace std;

class PrefixExpressionEvaluator {

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

            for(int i=expression.length()-1; i>=0; i--) {
                if(expression[i] == ' ')
                    continue;
                else if(isdigit(expression[i])) {
                    int j = i;
                    int val = 0;
                    while(j >= 0 && isdigit(expression[j])) {
                        j--;
                    }
                    j++;
                    i=j;
                    while(j < expression.length() && isdigit(expression[j])) {
                        val = val*10 + (expression[j] - '0');
                        j++;
                    }
                    operands.push(val);
                }
                else {
                    int val1 = operands.top();
                    operands.pop();

                    int val2 = operands.top();
                    operands.pop();

                    operands.push(calculate(val1, val2, expression[i]));
                }
            }

            return operands.top();
        }

};

int main() {
    PrefixExpressionEvaluator e;
    cout << e.evaluate("* + 6 9 - 3 1") << "\n";
    cout << e.evaluate("+ * 100 2 12") << "\n";
    cout << e.evaluate("+ 9 * 12 6") << "\n";
    cout << e.evaluate("- * 100 2 12") << "\n";
    cout << e.evaluate("/ * 100 + 2 12 14") << "\n";
    cout << e.evaluate("- + * 2 3 * 5 4 9") << "\n";
}