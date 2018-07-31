# coding: utf-8
# 深度优化算法

result = [0] * 8

count = 0


def xie_xian(y):
    for i in xrange(y):
        case1 = result[i] == result[y] or abs(y - i)  # 同一行
        case2 = abs(y - i) == abs(result[y] - result[i])  # 在斜线上
        if case1 or case2:
            return False
    return True


def eight_qu(y=0):
    for x in xrange(8):
        result[y] = x
        if xie_xian(y):
            if y <= 6:
                eight_qu(y + 1)
            else:
                print result
                global count
                count += 1

eight_qu()