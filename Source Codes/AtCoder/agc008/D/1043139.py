import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7


def main():
    n = int(input())
    a = list(map(int, input().split()))
    nn = n*n
    r = [-1] * nn
    ms = []
    us = []
    for i in range(n):
        c = i+1
        ri = a[i] - 1
        r[ri] = c
        ms.append([ri, i, c])
        us.append([ri, n-i-1, c])
    ms.sort()
    si = 0
    for ri, k, c in ms:
        for _ in range(k):
            while r[si] > 0 and si < (nn-1):
                si += 1
            if si > ri or r[si] > 0:
                print('No')
                return
            r[si] = c

    si = nn-1
    us.sort()
    us.reverse()
    for ri, k, c in us:
        for _ in range(k):
            while r[si] > 0 and si > 0:
                si -= 1
            if si < ri or r[si] > 0:
                print('No')
                return
            r[si] = c

    print('Yes')
    print(' '.join(map(str, r)))


main()