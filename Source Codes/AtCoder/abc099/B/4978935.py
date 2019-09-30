import sys
sys.setrecursionlimit(100000)
a, b = map(int, input().split())

def calc(n):
    if n == 1:
        return 1
    else:
        return calc(n-1) + n

print(calc(b - a) - b)