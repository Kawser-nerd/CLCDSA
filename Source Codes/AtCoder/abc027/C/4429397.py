from math import log2
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def left(x):
    return 2*x


def right(x):
    return 2*x+1


def floor(x):
    return x//1


def depth(x):
    return floor(log2(x))+1


def solve():
    n = int(input())
    turn = True
    d = depth(n)
    if d % 2 == 0:
        taka = (lambda x: left(x))
        aoki = (lambda x: right(x))
    else:
        aoki = (lambda x: left(x))
        taka = (lambda x: right(x))

    x = 1
    while x <= n:
        if turn:
            x = taka(x)
        else:
            x = aoki(x)
        turn = not turn
    if turn:
        print("Takahashi")
    else:
        print("Aoki")


solve()