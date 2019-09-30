import sys,collections

def solve():
    N = int(input())
    L = list(map(int,input().split()))
    ans = 0
    tmp = 0
    for i,v in enumerate(L):
        if i+1 == v:
            tmp += 1
        else:
            ans += -(-tmp//2)
            tmp = 0
    print(ans + -(-tmp//2))
    
solve()