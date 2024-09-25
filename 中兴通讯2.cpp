#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>


int evaluateExpression(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (std::getline(tokens, token, ',')) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // 操作符，弹出两个元素进行计算
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                // 确保除数不为0
                if (b == 0) {
                    throw std::runtime_error("Division by zero.");
                }
                stack.push(a / b);
            }
        } else {
            // 数字，直接压栈
            stack.push(std::stoi(token));
        }
    }

    // 栈中应该只剩下一个元素，即表达式的结果
    return stack.top();
}

int main() {
    std::string inputExpression = "2,1,+,3,*,5,*,9,/";
    try {
        int result = evaluateExpression(inputExpression);
        std::cout << "The result is: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}