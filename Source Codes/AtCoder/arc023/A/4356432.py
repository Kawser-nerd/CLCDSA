# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def ceil(x):
    return(-x)//1*(-1)


def calc(y, m, d):
    return 365*y + y//4 - y // 100+y//400+(306*(m+1))//10 + d - 429


y = int(input())
m = int(input())
d = int(input())

if m == 1:
    m = 13
    y -= 1
elif m == 2:
    m = 14
    y -= 1

de = calc(2014, 5, 17)
print(de - calc(y, m, d))