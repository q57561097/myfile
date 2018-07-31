# coding=utf-8
# 快速排序
"""1 从数列中挑出一个元素，称为 “基准”（pivot），
2 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。
3 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

递归的最底部情形，是数列的大小是零或一，也就是永远都已经被排序好了。虽然一直递归下去，但是这个算法总会退出，因为在每次的迭代（iteration）中，它至少会把一个元素摆到它最后的位置去。"""


def quick_sort(s, left, right):
    if left < right:
        l, r, x = left, right, s[left]
        while l < r:
            while l < r and s[r] >= x:
                r -= 1
            if l < r:
                print l, r
                s[l] = s[r]
                l +=1
            while l < r and s[l] < x:
                l += 1
            if l < r:
                s[r] = s[l]
                r -= 1
        s[l] = x
        # 挖坑填坑
        quick_sort(s, left, l-1)
        quick_sort(s, l+1, right)
s1 = [5,13,6,24,2,8,19,27,6,12,1,17]
quick_sort(s1, 0,11)
print s1