N=int(input())

import sys
sys.setrecursionlimit(10**5)
ab=[list(map(int, input().split())) for _ in range (N-1)]
con=[[] for _ in range(N+1)]

#print(ab)
for a,b in ab :
  con[a].append(b)
  con[b].append(a)

#black Fennec
pc=[0]*(N+1)
q=[(1,0)]
vis=[False]*(N+1)
vis[1]=True
Fcnt=N
while q:
  n,c=q.pop()
  pc[n]=c
  for ch in con[n]:
    if vis[ch]==True:
      continue
    vis[ch]=True
    q.append((ch,c+1))
    
q=[(N,0)]
vis=[False]*(N+1)
vis[N]=True
while q:
  n,c=q.pop()
  if pc[n]>c:
    Fcnt-=1
  for ch in con[n]:
    if vis[ch]==True:
      continue
    vis[ch]=True
    q.append((ch,c+1))
    
if Fcnt>N-Fcnt:
  print("Fennec")
else:
  print("Snuke")