N,M = map(int,input().split())
alist=[]
blist=[]
for i in range(M):
  a,b=map(int,input().split())
  alist.append(a)
  blist.append(b)
father=[i for i in range(N+1)]
rank=[0]*(N+1)
size=[1]*(N+1)

def find(x):
  if x!=father[x]:
    father[x]=find(father[x])
  return father[x]

def union(x,y):
  xfa,yfa=find(x),find(y)
  if xfa==yfa:
    return
  elif rank[xfa]<rank[yfa]:
    father[xfa]=yfa
    size[yfa]+=size[xfa]
  else:
    father[yfa]=xfa
    size[xfa]+=size[yfa]
    if rank[xfa]==rank[yfa]:
      rank[xfa]+=1
      
def samefather(x,y):
  return find(x)==find(y)

ans_list=[]
ans=int(N*(N-1)/2)
for i in range(M):
  ans_list.append(ans)
  a=alist[M-1-i]
  b=blist[M-1-i]
  p,q=size[find(a)],size[find(b)]
  if samefather(a,b):
    continue
  else:
    ans-=p*q
    union(a,b)
for i in range(M):
  print(ans_list[M-1-i])