/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-26 10:29:30
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-27 16:01:47
 */

/*题目



*/
#include <iostream>
#include <string>


bool matchesPattern(const std::string& text, const std::string& pattern, size_t tIndex = 0, size_t pIndex = 0) {
    // 基准情况：如果模式已经完全匹配，则返回true
    if (pIndex == pattern.size()) {
        return tIndex == text.size();
    }

    // 如果模式当前字符是'*'，有两种可能：
    // 1. '*' 表示空字符串，所以我们跳过'*'继续匹配
    // 2. '*' 表示任意字符，所以我们跳过 text 的当前字符继续匹配
    if (pattern[pIndex] == '*') {
        // 情况1: 跳过'*'继续匹配
        if (matchesPattern(text, pattern, tIndex, pIndex + 1)) {
            return true;
        }
        // 情况2: 如果text还有字符，跳过text的当前字符继续匹配
        if (tIndex < text.size()) {
            return matchesPattern(text, pattern, tIndex + 1, pIndex);
        }
        // 如果text没有更多字符，但模式中只有'*'，则匹配成功
        return pattern.find_first_not_of('*', pIndex) == std::string::npos;
    }

    // 如果text和pattern的当前字符匹配，或者pattern的当前字符是'.'
    if (tIndex < text.size() && (text[tIndex] == pattern[pIndex] || pattern[pIndex] == '?')) {
        return matchesPattern(text, pattern, tIndex + 1, pIndex + 1);
    }

    // 不匹配
    return false;
}

int main() {
    std::string text;
    std::string pattern;
    std::cout << "Enter the text: ";
    std::cin >> text;
    std::cout << "Enter the pattern: ";
    std::cin >> pattern;

    if (matchesPattern(text, pattern)) {
        std::cout << "The pattern matches the text." << std::endl;
    } else {
        std::cout << "The pattern does not match the text." << std::endl;
    }

    return 0;
}