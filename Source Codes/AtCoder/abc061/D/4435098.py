import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N,M = map(int, input().split())
abc = [[int(j) for j in input().split()] for _ in range(M)]
con=[[] for _ in range (N+1)]
inf = float("inf")

allcost = [ -inf] * (N+1)
allcost[1] = 0

for i in range(M):
    a,b,c = abc[i]
    con[a].append(b)

for n in range(1, N):
    for edge in range(M):
        a,b,c = abc[edge]
        if allcost[b] < allcost[a] + c:
            allcost[b] = allcost[a] + c
neg=[False]*(N+1)
for edge in range(M):
    a,b,c = abc[edge]
    if allcost[a] + c > allcost[b]:
        neg[b]=True
    if neg[a]==True:
      neg[b]=True
if neg[N]:
  print("inf")
  exit(0)
print(allcost[N])