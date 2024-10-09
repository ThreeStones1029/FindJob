'''
Description: 
version: 
Author: ThreeStones1029 2320218115@qq.com
Date: 2024-10-06 19:35:14
LastEditors: ShuaiLei
LastEditTime: 2024-10-06 19:35:18
'''
class MyClass:
    def __init__(self):
        self.__private_var = 42  # 定义私有成员

    def get_private_var(self):
        return self.__private_var  # 类内部可以访问私有成员


obj = MyClass()

# 类内部可以正常访问私有成员
print(obj.get_private_var())  # 输出 42

# 试图通过对象直接访问私有成员会报错
# print(obj.__private_var)  # AttributeError: 'MyClass' object has no attribute '__private_var'

# 但是可以通过名称重整机制访问
print(obj._MyClass__private_var)  # 输出 42