# coding: utf-8
import heapq
n=int(input())
p=[]
d=[[] for i in range(n)]
for i in range(n):
    p.append(tuple(map(int,input().split()))+tuple([i]))
x_sorted=sorted(p,key=lambda x:x[0])
y_sorted=sorted(p,key=lambda x:x[1])
for i in range(n-1):
    d[x_sorted[i][2]].append((x_sorted[i+1][0]-x_sorted[i][0],x_sorted[i+1][2]))
    d[x_sorted[i+1][2]].append((x_sorted[i+1][0]-x_sorted[i][0],x_sorted[i][2]))
    d[y_sorted[i][2]].append((y_sorted[i+1][1]-y_sorted[i][1],y_sorted[i+1][2]))
    d[y_sorted[i+1][2]].append((y_sorted[i+1][1]-y_sorted[i][1],y_sorted[i][2]))
h=[]
for q in d[0]:
    heapq.heappush(h,q)
used=[False for i in range(n)]
used[0]=True
cost=0
while len(h):
    q=heapq.heappop(h)
    if used[q[1]]:
        continue
    used[q[1]]=True
    cost+=q[0]
    for r in d[q[1]]:
        heapq.heappush(h,r)
print(cost)