import heapq

N,K = map(int,input().split())
L = list(map(int,input().split()))

q = []
heapq.heapify(q)

for i,a in enumerate(L[:K]) :
    heapq.heappush(q, (-a,i+1))

for i,a in enumerate(L[K:]) :
    b,j = q[0]
    print(j)
    if a < -b :
        heapq.heappop(q)
        heapq.heappush(q, (-a,K+i+1))
b,j = q[0]
print(j)