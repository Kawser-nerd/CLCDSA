N=int(input())
R=[[int(i) for i in input().split()] for i in range(N)]
B=[[int(i) for i in input().split()] for i in range(N)]
List=[[] for i in range(N)]
count=[0]*N
unpaired=[True]*N

for i,r in enumerate(R):
  for j,b in enumerate(B):
    if b[0]>r[0] and b[1]>r[1]:
      List[i].append(j)
      count[j]+=1    
List.sort(key=lambda x:len(x))

ans=0
for l in List:
  k=float("inf")
  p=-1
  for j in l:
    if unpaired[j]:
      if k>count[j]:
        k=count[j]
        p=j
      count[j]-=1
  if p>=0:
    ans+=1
    unpaired[p]=False
print(ans)