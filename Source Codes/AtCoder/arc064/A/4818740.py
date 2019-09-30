import sys
input=sys.stdin.readline
n,x=map(int,input().split())
A=list(map(int,input().split()))
cnt=0

if A[0]>x:
  cnt+=A[0]-x
  A[0]-=A[0]-x

for i in range(1,n):
  total= A[i]+A[i-1]
  if total>x:
    cnt+=total-x
    A[i]-=total-x
print(cnt)