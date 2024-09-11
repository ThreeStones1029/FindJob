/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-11 15:39:51
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-11 15:42:35
 */
#include <iostream>
#include <string>

std::string removeConsecutiveChars(const std::string& s) {
    std::string result;
    int i = 0;

    while (i < s.length()) {
        int count = 1;

        // 统计连续相同字符的数量
        while (i + count < s.length() && s[i] == s[i + count]) {
            count++;
        }

        // 如果连续字符少于3个，则保留
        if (count < 3) {
            result += s.substr(i, count);
        }

        // 跳过连续的字符
        i += count;
    }

    return result;
}

std::string removeAllConsecutiveChars(std::string s) {
    std::string prev;

    // 不断重复移除，直到字符串不再变化
    do {
        prev = s;
        s = removeConsecutiveChars(s);
    } while (s != prev);  // 当字符串没有变化时退出循环

    return s;
}

int main() {
    std::string s = "111BCC111CB";
    std::string result = removeAllConsecutiveChars(s);
    std::cout << "最终结果: " << result << std::endl;  // 输出 "BB"
    return 0;
}
