import math
INF, MOD = float("inf"), 10 ** 9 + 7
MAX, MIN = -INF, INF
dx1, dy1, dx2, dy2 = [-1, 0, 1, 0], [0, -1, 0, 1], [-1, 0, 1, -1, 1, -1, 0, 1], [-1, -1, -1, 0, 0, 1, 1, 1]

def get_int():
    return int(input())

def get_int_list():
    return list(map(int, input().split()))

def mins(x, y):
    x = min(x, y)

def maxs(x, y):
    x = max(x, y)

def fact(n):
    tmp = 1
    for i in range(2, n + 1):
        tmp = int(tmp * i % MOD)
    return tmp

while(True):
    try:
        n, m = get_int_list()
        if(n == m):
            print(int(fact(n) ** 2 * 2 % MOD))
        elif(abs(n - m) == 1):
            print(int(fact(n) * fact(m) % MOD))
        else:
            print(0)
    except EOFError:
        exit()