def quick_sort(s, left, right):
    if left < right:
        l, r, x = left, right, s[left]
        while l < r:
            print l, r
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
        quick_sort(s, left, l-1)
        quick_sort(s, l+1, right)
s1 = [5,13,6,24,2,8,19,27,6,12,1,17]
quick_sort(s1, 0,11)
print s1