N=int(input())
A=list(map(int,input().split(' ')))
X,Y=A[0],sum(A)-A[0]
ans=abs(X-Y)
for i in range(N-2):
  X+=A[i+1]
  Y-=A[i+1]
  if abs(X-Y)<ans:
    ans=abs(X-Y)
print(ans)