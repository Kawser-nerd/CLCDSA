import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7

def f():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    i = 1
    if n > 2 and a[-1] == 1:
        return 'Impossible'
    if a[-1] != a[-2]:
        return 'Impossible'
    if a[-1] % 2 == 1:
        if a[-1] // 2 + 1 != a[0]:
            return 'Impossible'
        if a[0] != a[1]:
            return 'Impossible'
        if n > 2 and a[0] == a[2]:
            return 'Impossible'
        i = 2
    else:
        if a[-1] // 2 != a[0]:
            return 'Impossible'
        if a[0] == a[1]:
            return 'Impossible'
    c = 2
    t = a[0]
    for j in range(i,n):
        if t != a[j]:
            if c < 2:
                return 'Impossible'
            if t + 1 != a[j]:
                return 'Impossible'
            c = 0
            t = a[j]
        c += 1
    return 'Possible'

print(f())