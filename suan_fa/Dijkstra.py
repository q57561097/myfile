# coding: utf-8
# 戴克斯特拉算法


"""算法步骤：

初始时令 S={V0},T={其余顶点}，T中顶点对应的距离值
若存在<V0,Vi>，d(V0,Vi)为<V0,Vi>弧上的权值
若不存在<V0,Vi>，d(V0,Vi)为∞

从T中选取一个其距离值为最小的顶点W且不在S中，加入S

对其余T中顶点的距离值进行修改：若加进W作中间顶点，从V0到Vi的距离值缩短，则修改此距离值

"""

length = {"AB": 6, "AC": 3, "BC": 2, "BD": 5, "CD": 3, "CE": 4, "DE": 2, "DF": 3, "EF": 5}
length2 = {}
S = {"A": 0}
V = {}
for value in "ABCDEF":
    length2[value] = {}
    V[value] = -1
for key, value in length.items():
    key1 = key[0]
    key2 = key[1]
    length2[key1][key2] = value
    length2[key2][key1] = value

now_point = "A"
len_key = len(V.keys())
while len_key >1:
    now_key = ""
    now_value = 100
    point_value = S.get(now_point, 0)
    for key, value in length2.get(now_point).items():
        if key in S.keys():
            continue
        value1 = V.get(key, -1)
        value += point_value
        if value1 != -1 :
            if value1 < value:
                value = value1
            else:
                V[key] = value
        else:
            V[key] = value
        if value < now_value:
            now_value = value
            now_key = key
    S[now_key] = now_value
    V.pop(now_key)
    now_point = now_key
    len_key -= 1

print S, 123
print V, 456