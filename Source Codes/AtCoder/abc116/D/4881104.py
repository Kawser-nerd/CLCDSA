import heapq

N,K=map(int,input().split())
L=[]

for _ in range(N):
    (t,d)=map(int,input().split())
    heapq.heappush(L,(-d,t))

LL=[]
sum=0
used=set()

for i in range(K):
    d,t=heapq.heappop(L)
    if t in used:
        heapq.heappush(LL,(-d,t))
    used.add(t)
    sum+=-d

ans=len(used)**2+sum

while L and LL:
    d,t=heapq.heappop(L)
    if t not in used:
        used.add(t)
        dd,_=heapq.heappop(LL)
        sum=sum-dd+(-d)
        ans=max(ans,len(used)**2+sum)

print(ans)