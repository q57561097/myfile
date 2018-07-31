# coding:utf-8
# 广度优先搜索算法


from copy import deepcopy


maze =[[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
       [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1],
       [0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
       [0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0],
       [0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0],
       [1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1],
       [1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1],
       [1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1],
       [1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1],
       [1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1],
       [1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1],
       [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

                ]


b = '%s' * 12

finally_result = []


def mi_gong(x, y, result=[]):

    list1 = []
    for k in [x + 1, x - 1]:
        if 0 <= k <= 11:
            list1.append((k,
                          y))

    for z in [y+1, y-1]:
        if 0 <= z <= 11:
            list1.append((x, z))
    for i in list1:
        result2 = deepcopy(result)
        if maze[i[1]][i[0]] == 0:
            h = i[0]
            l = i[1]
            maze[i[1]][i[0]] = "*"
            result2.append((i[0], i[1]))
            if (h, l) == (11, 2):
                maze[2][11] = 0
                finally_result.append(result2)
            elif 0 <= x <= 11 and 0 <= y <= 11:

                mi_gong(h, l, result2)


mi_gong(0, 3)
index = 0
for n in maze:
    print b % tuple(n), index
    index += 1