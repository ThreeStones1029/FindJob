/*
 * @Description: 
 * @version: 
 * @Author: 帅磊240108 2158097607@xiaomi.com
 * @Date: 2024-08-31 19:52:11
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-08-31 20:15:00
 */
#include <iostream>


// void test(int *p)
// {
//     int a = 1;
//     p = &a;
//     std::cout << p << " " << *p << std::endl;
// }


// int main()
// {
//     int *p = NULL;
//     test(p);
//     if(p == NULL)
//     std::cout << "指针p为NULL" << std::endl;
//     return 0;
// }
//运行结果为：
//0x22ff44 1
//指针p为NULL


void testPTR(int* p) {
	int a = 12;
	p = &a;
}

void testREFF(int& p) {
	int a = 12;
	p = a;
}

int main()
{
	int a = 10;
	int* b = &a;
    int& c = a;
	testPTR(b);//改变指针指向，但是没改变指针的所指的内容
	std::cout << a << std::endl;// 10
	std::cout << *b << std::endl;// 10
    std::cout << "pointer size: " << sizeof(b) << std::endl;
    std::cout << "int size: " << sizeof(c) << std::endl;

	a = 10;
	testREFF(a);
	std::cout << a << std::endl;//12
}
