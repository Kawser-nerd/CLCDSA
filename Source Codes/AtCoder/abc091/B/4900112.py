from collections import defaultdict
N=int(input())
d=defaultdict(int)
for i in range(N):
  d[input()]+=1
M=int(input())
for i in range(M):
  d[input()]-=1
ans=0
for key in d:
  ans=max(ans,d[key])
print(ans)