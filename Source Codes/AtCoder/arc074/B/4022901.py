import heapq

n=int(input())
*a,=map(int,input().split())
inf=float("inf")

pos=n
q,r=[],[]
u,d=[-inf]*(3*n),[inf]*(3*n)

for i in range(n):
    heapq.heappush(q,a[i])
    u[i]=u[i-1] if i else 0
    u[i]+=a[i]

for i in range(n,2*n):
    heapq.heappush(q,a[i])
    b=heapq.heappop(q)
    u[i]=u[i-1]+a[i]-b

for i in range(2*n,3*n)[::-1]:
    heapq.heappush(r,-a[i])
    d[i]=d[i+1] if i!=3*n-1 else 0
    d[i]+=a[i]

for i in range(n,2*n)[::-1]:
    heapq.heappush(r,-a[i])
    b=heapq.heappop(r)
    d[i]=d[i+1]+a[i]+b

ans=-inf
for i in range(n-1,2*n):
    ans=max(ans,u[i]-d[i+1])

print(ans)