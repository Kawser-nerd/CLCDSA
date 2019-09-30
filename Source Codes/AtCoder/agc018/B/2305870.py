N,M=map(int,input().split())
A=[]
for i in range(N):
  a=[int(x) for x in input().split()]
  A.append(a)
  
def solve():
  res=[ 0 for x in range(M+1)]
  for i in range(N):
    res[A[i][0]]+=1
  ans=max(res)
  jud=res.index(ans)
  for j in range(N):
    A[j].remove(jud)
  return ans

minans=N
for i in range(M):
  minans=min(solve(),minans)
print(minans)