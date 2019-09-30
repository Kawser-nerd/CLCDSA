import sys,collections
from collections import defaultdict

def update_minA(minA,t):
    if minA > t:
        return t
    return minA

def check_range(y,x,H,W):
    return 0 < x and x < W and 0 < y and y < H 

def solve():
    N,T = map(int,input().split())
    A = list(map(int,input().split()))
    minA = float("inf")
    P = defaultdict(lambda:0)
    for i,v in enumerate(A):
        if i != 0:
            P[v - minA] += 1
        minA = update_minA(minA,v)
    print(P[max(P)])
    
solve()