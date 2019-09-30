import itertools
N,C=map(int,input().split())
L=[[0 for i in range(C)] for j in range(3)]
D=[]
for i in range(C):
  D.append([int(x) for x in input().split()])
for i in range(N):
  s=[int(x)-1 for x in input().split()]
  for j in range(N):
    L[(i+j)%3][s[j]]+=1
ans=float("inf")
for per in itertools.permutations(range(C),3):
  kans=sum(sum(D[x][per[i]]*L[i][x] for x in range(C))for i in range(3))
  ans=min(ans,kans)
print(ans)