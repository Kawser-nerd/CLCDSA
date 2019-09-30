import sys
from collections import defaultdict

# sys.stdin = open('c1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


def pos(X, Y):
    if Y == 0:
        return X
    if X == r:
        return r + Y
    if Y == c:
        return r + c + r - X
    if X == 0:
        return r + c + r + c - Y


r, c, n, = read_int_list()
x = [0, 0]
y = [0, 0]
a = []
for i in range(n):
    x[0], y[0], x[1], y[1] = read_int_list()
    if (x[0] in [0, r] or y[0] in [0, c]) and (x[1] in [0, r] or y[1] in [0, c]):
        for k in range(2):
            a.append((pos(x[k], y[k]), i))
m = len(a) // 2
a.sort()

res = 'YES'
started = set()
s = []
for p, i in a:
    if i not in started:
        started.add(i)
        s.append(i)
    else:
        if s[-1] != i:
            res = 'NO'
            break
        s.pop()

print(res)