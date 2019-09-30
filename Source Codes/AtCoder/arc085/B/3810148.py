import sys,collections

inf = float("inf")

def solve():
    N,Z,W = map(int,input().split())
    L = list(map(int,input().split()))
    if N>1:
        print(max(abs(L[-2]-L[-1]),abs(L[-1]-W)))
    else:
        print(abs(L[0]-W))
solve()