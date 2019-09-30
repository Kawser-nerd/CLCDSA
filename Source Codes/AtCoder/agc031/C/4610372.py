#!usr/bin/env python3
from collections import defaultdict
from collections import deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS():return list(map(list, sys.stdin.readline().split()))
def S(): return list(sys.stdin.readline())[:-1]
def IR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = I()
    return l
def LIR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = LI()
    return l
def SR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = S()
    return l
def LSR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = SR()
    return l
mod = 1000000007

#A
def A():
    n = I()
    s = S()
    d = defaultdict(int)
    for i in s:
        d[i] += 1
    ans = 1
    for i in d.keys():
        ans *= d[i]+1
        ans %= mod
    print(ans-1)
#B
def B():
    n = I()
    c = IR(n)
    v = [[i+1] for i in range(n-1)]
    v.append([])
    d = defaultdict(deque)
    for i in range(n):
        d[c[i]].append(i)
    for i in d.keys():
        x = None
        while d[i]:
            y = d[i].popleft()
            if x != None and y != x+1:
                v[x].append(y)
            x = y
    path = [0]*(n)
    path[0] = 1
    q = [0]
    for x in range(n-1):
        for y in v[x]:
            path[y] += path[x]
            path[y] %= mod
    print(path[-1])
#C
def C():
    def dfs(ans,l,r,d):
        if r != l+1:
            i = n-1
            c = ans[l]^ans[r]
            while not c&po2[i]:i -= 1
            d[i] = 1
            j = 0
            while d[j] or i == j:j += 1;j %= n
            m = (l+r)//2
            ans[m] = ans[l]^po2[j]
            ans[m+1] = ans[m]^po2[i]
            dfs(ans,l,m,d[:i]+[1]+d[i+1:])
            dfs(ans,m+1,r,d[:i]+[1]+d[i+1:])
    n,a,b = LI()
    po2 = [1]*(n+1)
    for i in range(1,n+1):
        po2[i] = po2[i-1]*2
    k = b^a
    c = 0
    bi = []
    i = 0
    g = [0]*n
    while k > 0:
        if k%2:
            bi.append(i)
            g[i] = 1
        c += k%2
        k//= 2
        i += 1
    f = c
    bi = bi[::-1]
    if not f%2:
        print("NO")
        quit()
    ans = [0]*po2[n]
    ans[0] = a
    ans[po2[n]-1] = b
    d = [0]*n
    dfs(ans,0,po2[n]-1,d)
    print("YES")
    print(*ans)
#D
def D():
    return

#E
def E():
    return

#F
def F():
    return

#G
def G():
    return

#H
def H():
    return

#Solve
if __name__ == "__main__":
    C()