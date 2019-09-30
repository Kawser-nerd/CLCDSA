# coding:utf-8

import sys
import heapq
# from collections import Counter, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    s = SI()

    ss = [ord(c) for c in s]
    abc = [ord(c) for c in 'abcdefghijklmnopqrstuvwxyz']
    if len(s) < 26:
        sss = set(ss)
        for c in abc:
            if c not in sss:
                return s + chr(c)
    hq = []
    prev = ss[-1]
    for i in range(len(s))[::-1]:
        c = ss[i]
        if c >= prev:
            heapq.heappush(hq, c)
        else:
            while hq and hq[0] < c:
                heapq.heappop(hq)
            return s[:i] + chr(hq[0])
        prev = c

    return -1


print(main())