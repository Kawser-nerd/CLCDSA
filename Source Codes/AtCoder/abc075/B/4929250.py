import math
import functools
import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

def judge(n,m):
    if (0 <= n < H) and (0 <= m < W) and s[n][m]=="#":
        return True

def cnt(a,b):
    l = [-1,0,1]
    num = 0
    for i in l:
        for j in l:
            if i == j == 0:
                continue
            else:
                if judge(a+i,b+j):
                    num += 1
    return num

H,W = IL()
s = [[i for i in S()] for i in range(H)]
ans = [["#" for i in range(W)] for i in range(H)]

for i in range(H):
    for j in range(W):
        if s[i][j] == ".":
            ans[i][j] = cnt(i,j)

for i in ans:
    print("".join(list(map(str,i))))