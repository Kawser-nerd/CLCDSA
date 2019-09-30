import sys
input=sys.stdin.readline
n,x=map(int,input().split())
A=list(map(int,input().split()))
T=A[:]
ans=sum(T)
for j in range(1,n):
    T=[min(T[i],A[i-j]) for i in range(n)]
    ans=min(ans,sum(T)+x*j)
print(ans)