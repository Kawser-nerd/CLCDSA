import math

N = int(input())
pt = 1
pa = 1
for i in range(N):
    t, a = map(int, input().split())

    t_ratio = pt // t
    a_ratio = pa // a
    if pt % t != 0:
        t_ratio += 1
    if pa % a != 0:
        a_ratio += 1
    min_ratio = max(t_ratio, a_ratio)
    pt = t * min_ratio
    pa = a * min_ratio

print(pt+pa)