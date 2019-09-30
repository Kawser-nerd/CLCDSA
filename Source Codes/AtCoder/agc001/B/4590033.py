import sys
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n,x = na()

def loop(a,b):
    h = max(a,b)
    w = min(a,b)
    if h%w == 0:
        return int((2*h/w-1)*w)
    else:
        m = h%w
        q = h//w
        return 2*q*w + loop(m,w)

print(loop(x,n-x)+n)