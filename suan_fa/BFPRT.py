# coding: utf-8
# 线性查找算法
"""算法步骤：

将n个元素每5个一组，分成n/5(上界)组。

取出每一组的中位数，任意排序方法，比如插入排序。

递归的调用selection算法查找上一步中所有中位数的中位数，设为x，偶数个中位数的情况下设定为选取中间小的一个。

用x来分割数组，设小于等于x的个数为k，大于x的个数即为n-k。

若i==k，返回x；若i<k，在小于x的元素中递归查找第i小的元素；若i>k，在大于x的元素中递归查找第i-k小的元素。

"""


def get_center_num1(nums):
    nums.sort()
    return nums[len(nums) /2]


def get_center_num(nums):
    length = len(nums)
    center_list = []
    num = length / 5
    for i in xrange(num):
        center_list.append(get_center_num1(nums[i*5: i*5+5]))
    mid = num / 2
    if num % 2 == 0:
        return min(center_list[mid-1], center_list[mid])
    else:
        return center_list[mid]


def get_index_num(nums, index):
    length = len(nums)
    num = length / 5
    if index >= length:
        return nums[-1]
    if num <= 1:
        nums.sort()
        if index <= length-1:
            return nums[index]
        center_num = nums[length /2]
    else:
        center_num = get_center_num(nums)
    left = []
    right = []
    for i in xrange(length):
        value = nums[i]
        if value <= center_num:
            left.append(value)
        else:
            right.append(value)
    left_size = len(left)
    if index == left_size:
        return center_num
    if index > left_size:
        return get_index_num(right, index-left_size)
    else:
        return get_index_num(left, index)


num_list = [4, 1, 2, 56, 24, 5, 6, 97, 8, 0, 4, 8, 6, 2, 3, 6, 1, 9, 3, 4, 6, 2]
need = 0
num_list2 = sorted(num_list)
print get_index_num(num_list, need)
print num_list2[need]