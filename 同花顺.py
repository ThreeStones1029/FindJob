# class Parent(object):
#     x = 1

# class Child1(Parent):
#     pass

# class Child2(Parent):
#     pass

# print(Parent.x, Child1.x, Child2.x)
# Child1.x = 2
# print(Parent.x, Child1.x, Child2.x)
# Parent.x = 3
# print(Parent.x, Child1.x, Child2.x)


def max_subarray(arr):
    max_sum = arr[0]  # 最大和
    current_sum = arr[0]  # 当前和
    start = 0  # 当前子数组起始索引
    end = 0    # 最大子数组结束索引
    temp_start = 0  # 临时起始索引

    for i in range(1, len(arr)):
        if arr[i] > current_sum + arr[i]:
            current_sum = arr[i]
            temp_start = i  # 更新临时起始索引
        else:
            current_sum += arr[i]

        if current_sum > max_sum:
            max_sum = current_sum
            start = temp_start  # 更新最大子数组的起始索引
            end = i  # 更新最大子数组的结束索引

    return max_sum, arr[start:end + 1]  # 返回最大和及子数组

# 示例
arr = [-2, 1, -3, 4, 1, 2, 1, -5, 4, 5, 1]
result_sum, subarray = max_subarray(arr)
print("最大子数组和是:", result_sum)
print("最大子数组是:", subarray)

