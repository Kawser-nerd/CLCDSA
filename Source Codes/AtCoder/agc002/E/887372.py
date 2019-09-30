import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7


def f():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    a.reverse()
    i = j = 0
    while i+1 < n and a[i+1] > j+1:
        i += 1
        j += 1
    if (a[i] - j - 1) % 2 == 1:
        return 'First'
    k = 0
    while i+1 < n and a[i+1] > j:
        i += 1
        k += 1
    if k % 2 == 1:
        return 'First'
    return 'Second'

print(f())