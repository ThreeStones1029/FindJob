'''
Description: 
version: 
Author: ThreeStones1029 2320218115@qq.com
Date: 2024-10-17 11:54:51
LastEditors: ShuaiLei
LastEditTime: 2024-10-17 16:43:26
'''
# 支持向量机是一种常见的分类算法，其基本的思想是找到一个超平面，使得两个类别的样本被该超平面分开，并且距离超平面最近的样本点（即支持向量）到超平面的距离最远。
# 在SVM的对偶问题中，我们要求求解一组拉格郎日乘数。在此题目中，我们简化这个问题，仅需要考虑两类问题，并且所有的数据都是线性可分的。我们使用硬间隔SVM，即不考虑噪声和异常点的影响，请根据输入描述和输出描述的要求，变成计算拉格郎日乘数。
# 输入描述：
# 输入的数据集为一个二维的list，该二维list中每一个子list的前两个元素为样本特征，最后一个元素表示样本的类别标签，其中1表示正类，-1表示负类。例如，[[1.0,2.0,1],[2.0,3.0,-1]]。
# 所有的特征值都是浮点数。其中终端输入每行表示一个子list，数字之间以空格间隔。
# 输出描述：
# 你可以假设SVM的对偶问题的解是唯一的。输出一个list，表示每个样本的拉格郎日乘数，保留两位小数，用字符串表示，例如['0.20','0.20']
# 可以使用python的numpy,scipy,pandas,scikit-learn
# python在保留0.00的时候可能出现负数，统一输出'0.00'
# 示例：
# 1.0 2.0 1
# 2.0 3.0 -1
# 输出['1.00','1.00']


import numpy as np
from scipy.optimize import minimize

def parse_input(input_str):
    # 将输入字符串解析成二维列表
    data = []
    for line in input_str.strip().split("\n"):
        parts = line.split()
        features = [float(parts[0]), float(parts[1])]
        label = int(parts[2])
        data.append(features + [label])
    return data

def dual_objective(alpha, X, y):
    # 计算目标函数的负值，因为scipy是求最小值
    m = len(y)
    term1 = np.sum(alpha)
    term2 = 0.5 * np.sum([alpha[i] * alpha[j] * y[i] * y[j] * np.dot(X[i], X[j])
                         for i in range(m) for j in range(m)])
    return term2 - term1

def solve_lagrange_multipliers(data):
    X = np.array([item[:2] for item in data])  # 样本特征
    y = np.array([item[2] for item in data])   # 类别标签
    m = len(y)
    
    # 初始拉格朗日乘数，所有元素为 0
    alpha0 = np.zeros(m)
    
    # 设置约束条件：sum(alpha[i] * y[i]) == 0
    cons = ({'type': 'eq', 'fun': lambda alpha: np.dot(alpha, y)})
    
    # 设置每个 alpha[i] >= 0
    bounds = [(0, None) for _ in range(m)]
    
    # 求解优化问题
    result = minimize(fun=dual_objective,
                      x0=alpha0,
                      args=(X, y),
                      method='SLSQP',
                      bounds=bounds,
                      constraints=cons)
    
    # 获取拉格朗日乘数并格式化
    alphas = result.x
    formatted_alphas = [f'{max(0, round(a, 2)):.2f}' for a in alphas]
    return formatted_alphas

# 示例输入
input_str = """1.0 2.0 1
2.0 3.0 -1"""

# 解析输入
data = parse_input(input_str)

# 计算拉格朗日乘数
lagrange_multipliers = solve_lagrange_multipliers(data)

# 输出结果
print(lagrange_multipliers)
