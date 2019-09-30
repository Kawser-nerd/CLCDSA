import sys,collections

def solve():
    N,x = map(int,input().split())
    L = list(map(int,input().split()))
    A = L[::]
    ans = sum(A)
    for k in range(N):
        A = [min(A[i], L[i - k]) for i in range(N)]
        ans = min(ans,sum(A) + k * x)
    print(ans)
    
solve()