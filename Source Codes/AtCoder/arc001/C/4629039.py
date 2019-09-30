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
    d = defaultdict(int)
    a = list(map(int,S()))
    for i in a:
        d[i] += 1
    d = list(d.values())
    if len(d) == 1:
        print(max(d),0)
    else:
        print(max(d),min(d))
#B
def B():
    a,b = LI()
    ans = float("inf")
    for i in range(-4,5):
        for j in range(-8,9):
            for k in range(-40,49):
                if a+i*10+j*5+k == b:
                    ans = min(ans,abs(i)+abs(j)+abs(k))
    print(ans)

#C
def C():
    def check(b,p):
        a = [[b[i][j] for j in range(8)] for i in range(8)]
        y,x = p
        if a[y][x]:
            return False
        for i in range(-8,8):
            if 0 <= y+i < 8:
                if i != 0 and s[y+i][x] == "Q":
                    return False
                a[y+i][x] = 1
                if 0 <= x+i < 8:
                    if i != 0 and s[y+i][x+i] == "Q":
                        return False
                    a[y+i][x+i] = 1
            if 0 <= x+i < 8:
                if i != 0 and s[y][x+i] == "Q":
                    return False
                a[y][x+i] = 1
                if 0 <= y-i < 8:
                    if i != 0 and s[y-i][x+i] == "Q":
                        return False
                    a[y-i][x+i] = 1
        return a

    def dfs(n,a,i,k,li):
        if n == 5:
            for y,x in k:
                s[y][x] = "Q"
            for a in s:
                for b in a:
                    print(b,end = "")
                print()
            quit()
        l = len(d[c[i]])
        for j in range(l):
            if li[d[c[i]][j]]:
                b = check(a,[c[i],d[c[i]][j]])
                if b:
                    dfs(n+1,b,i+1,k+[[c[i],d[c[i]][j]]],li[:d[c[i]][j]]+[0]+li[d[c[i]][j]+1:])
    s = SR(8)
    a = [[0 for i in range(8)] for j in range(8)]
    for y in range(8):
        for x in range(8):
            if s[y][x] == "Q":
                a = check(a,[y,x])
                if not a:
                    print("No Answer")
                    quit()
    d = defaultdict(list)
    for y in range(8):
        for x in range(8):
            if not a[y][x]:d[y].append(x)
    c = list(d.keys())
    li = [1 for i in range(8)]
    dfs(0,a,0,[],li)
    print("No Answer")
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