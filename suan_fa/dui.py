#  coding: utf-8
"""父节点i的左子节点在位置(2*i+1);
父节点i的右子节点在位置(2*i+2);
子节点i的父节点在位置floor((i-1)/2);"""
nums = [5, 13, 6, 24, 2, 8, 17, 27, 6, 12, 1, 19]

len_num = len(nums)


def sort_one(num_list, index, n):
    j = 2 * index + 1
    temp = num_list[index]
    while j < n:
        if j + 1 < n and num_list[j + 1] > num_list[j]:
            j += 1
        if num_list[j] <= temp:
            break
        num_list[index] = num_list[j]
        index = j
        j = 2 * index + 1
    num_list[index] = temp


i = (len_num - 2) / 2  # 获取最后一个父节点
while i >= 0:
    sort_one(nums, i, len_num)
    i -= 1
i = len_num-1
while i >= 1:
    temp = nums[0]
    nums[0] = nums[i]
    nums[i] = temp
    sort_one(nums, 0, i)
    i -= 1
print nums

