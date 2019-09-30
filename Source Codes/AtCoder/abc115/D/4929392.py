import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline
INF = float('inf')
MOD = 10**9+7
dy = [0,1,0,-1]
dx = [1,0,-1,0]
ddy = [0,1,1,1,0,-1,-1,-1]
ddx = [1,1,0,-1,-1,-1,0,1]

n,x = map(int,input().split())
P = [1]
L = [1]
for i in range(n):
    P.append(P[-1]*2+1)
    L.append(L[-1]*2+3)

def f(N,X):
    if N == 0:
        if X <= 0:
            return 0
        else:
            return 1
    elif X <= 1 + L[N-1]:
        return f(N-1,X-1)
    else:
        return P[N-1]+1+f(N-1,X-2-L[N-1])

print(f(n,x))