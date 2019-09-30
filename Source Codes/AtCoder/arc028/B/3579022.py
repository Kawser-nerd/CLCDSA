import heapq as q
r=lambda:map(int,input().split())
n,k=r()
*x,=r()
hq=[(-x[i],i+1) for i in range(k)]
q.heapify(hq)
for i in range(k,n):
  print(hq[0][1])
  q.heappushpop(hq,(-x[i],i+1))
print(hq[0][1])