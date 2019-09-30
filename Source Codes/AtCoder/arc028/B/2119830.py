import heapq
N,K = map(int,input().split())
src = list(map(int,input().split()))

hq = []
heapq.heapify(hq)
for i,a in enumerate(src[:K]):
    heapq.heappush(hq, (-a,i+1))

for i,a in enumerate(src[K:]):
    b,j = hq[0]
    print(j)
    if a < -b:
        heapq.heappop(hq)
        heapq.heappush(hq, (-a,K+i+1))
b,j = hq[0]
print(j)