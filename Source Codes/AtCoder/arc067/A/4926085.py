import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())


def era(n):
    data = [i for i in range(2, n + 1)]
    for d in data:
        data = [x for x in data if (x == d or x % d != 0)]
    data1 = []
    for d in data:
        data1.append([d, 1])
    return data1


mod = 10 ** 9 + 7
n = ni()
lis = era(n)
for i in range(1, n + 1):
    for j in range(len(lis)):
        if i < lis[j][0]:
            break
        elif i % lis[j][0] == 0:
            count = 0
            m = i
            while(m % lis[j][0] == 0):
                m = m // lis[j][0]
                count += 1
            lis[j][1] += count
ans = 1
for i in range(len(lis)):
    ans *= lis[i][1]
    ans %= mod
print(ans)