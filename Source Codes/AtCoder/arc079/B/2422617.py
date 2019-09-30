K=int(input())
N=50

def solve(A,cnt):
  res=len(A)
  for i in range(cnt):
    A[i]+=(res+1)
    for j in range(res):
      A[j]-=1
  return A

Ans=[0 for x in range(N)]
Ans[0]=25+(K//50)
for i in range(1,N):
  if i % 2 ==0:
    Ans[i]=Ans[i-1]+1
  else:
    Ans[i]=Ans[i-1]

Ans=solve(Ans,K%50)

print(N)
for i in range(N):
  if i == N-1:
    print(Ans[i])
  else:
    print(Ans[i],end=" ")