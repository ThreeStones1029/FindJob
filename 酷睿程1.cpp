/*
 * @Description
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-11-01 20:23:27
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-11-01 21:39:37
 */
// 给定字符串，返回字符串中，单词长度不超过指定长度的单词数目
// 输入：hello world， hello hehai，hello， cpp， hello ku rui cheng 4
// 输出：3

#include <iostream>
#include <string>
#include <cctype> // 用于isspace函数

int solution(int maxLength, std::string text) {
    int count = 0;
    int wordLength = 0;
    bool inWord = false;

    for (char ch : text) {
        if (std::isalpha(ch)) {
            wordLength++;
            inWord = true;
        } else if (inWord) {
            if (wordLength <= maxLength) {
                count ++;
            }
            wordLength = 0;
            inWord = false;
        }
    }

    // 检查最后一个单词（如果文本以单词结束）
    if (inWord && wordLength <= maxLength) {
        count ++;
    }

    return count;
}

int main() {
    int maxLength = 4;
    std::string text = "The Fox asked the stork, How is?";
    std::cout << "solution(maxLength, text) = " << solution(maxLength, text) << std::endl;
    return 0;
}