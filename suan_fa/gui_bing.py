# coding: utf-8
# 归并排序
"""算法步骤：

申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列

设定两个指针，最初位置分别为两个已经排序序列的起始位置

比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置

重复步骤3直到某一指针达到序列尾

将另一序列剩下的所有元素直接复制到合并序列尾"""

nums = [5, 13, 6, 24, 2, 8, 17, 27, 6, 12, 1, 19]


def merge_array(num_list, first, mid, last):
    l = first
    m = mid+1
    temp = []
    while l <= mid and m <= last:
        num1 = num_list[l]
        num2 = num_list[m]
        if num1 <= num2:
            temp.append(num1)
            l += 1
        else:
            temp.append(num2)
            m += 1
    while l <= mid:
        temp.append(num_list[l])
        l += 1
    while m <= last:
        temp.append(num_list[m])
        m += 1
    for index, value in enumerate(temp):
        num_list[first+index] = value


def merge_sort(num_list, first, last):
    if first < last:
        mid = (first+last) / 2
        merge_sort(num_list, first, mid)
        merge_sort(num_list, mid+1, last)
        merge_array(num_list, first, mid, last)

merge_sort(nums, 0, len(nums)-1)
print nums