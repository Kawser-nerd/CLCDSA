from bisect import bisect_left
n,m=map(int,input().split())
x,y=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

cnt=0
i=0
while i <=A[-1]:
  i=A[bisect_left(A,i)]+x
  if i <=B[-1]:
    i=B[bisect_left(B,i)]+y
    cnt+=1
  else:
    break
print(cnt)