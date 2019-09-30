import sys,collections

def solve():
    N = int(input())
    L = list(map(int,input().split()))
    ansn = max(L)
    n2 = ansn/2
    margin = float("inf")
    ansr = -1
    for v in L:
        if v == ansn:
            continue
        if margin > abs(n2-v):
            margin = abs(n2-v)
            ansr = v
    print(ansn,ansr)
    
solve()