import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n,m=map(int,input().split())
A=[0]*n
for _ in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    A[a]^=1
    A[b]^=1
print('NO' if any(A) else 'YES')