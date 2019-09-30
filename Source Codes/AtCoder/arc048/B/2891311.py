from bisect import bisect_left
sa=[]
ra=[]
ha=[[0,0,0] for i in range(10**5+1)]
n=int(input())
for _ in range(n):
  r,h=map(int,input().split())
  sa.append([r,h-1])
  ra.append(r)
  ha[r][h-1]+=1
ra.sort()

def jnk(c,l):
  if c==0:
    return [l[1],l[2],l[0]-1]
  if c==1:
    return [l[2],l[0],l[1]-1]
  if c==2:
    return [l[0],l[1],l[2]-1]

for i,j in sa:
  p=jnk(j,ha[i])
  p[0]+=bisect_left(ra,i)
  p[1]+=n-1-sum(p)
  print(*p)