import sys
r,c,k=map(int,input().split())
R1=[0]*r
C1=[0]*c
n=int(input())
candy=[[int(i) for i in l.split()] for l in sys.stdin]
for i in range(n):
  R1[candy[i][0]-1]+=1
  C1[candy[i][1]-1]+=1
R=sorted(R1)
C=sorted(C1)

def binary_search_min(x,line):
  ng=-1
  ok=len(line)
  while abs(ok-ng)>1:
    mid=(ok+ng)//2
    if line[mid]>=x:
      ok=mid
    else:
      ng=mid
  return ok
def binary_search(x,line):
  return binary_search_min(x+1,line)-binary_search_min(x,line)

ans=0
for i in range(k+1):
  ans+=binary_search(i,R)*binary_search(k-i,C)
for i in range(n):
  if R1[candy[i][0]-1]+C1[candy[i][1]-1]==k:
    ans-=1
  elif R1[candy[i][0]-1]+C1[candy[i][1]-1]==k+1:
    ans+=1
print(ans)