# coding: utf-8
# 二分法


num_list = [5, 13, 6, 24, 2, 8, 17, 27, 6, 12, 1, 19]


def half_sort(nums, num, fist, last):
    mid = (fist+last) /2
    mid_value = nums[mid]
    if num < mid_value:
        if mid == fist:
            nums.insert(mid, num)
        else:
            half_sort(nums, num, fist, mid-1)
    elif num == mid_value:
        nums.insert(mid, num)
    else:
        if mid == last:
            nums.insert(mid+1, num)
        else:
            half_sort(nums, num, mid+1, last)
temp = [num_list[0]]

for i in xrange(1, len(num_list)):
    value = num_list[i]
    half_sort(temp, value, 0, i-1)

print len(temp)