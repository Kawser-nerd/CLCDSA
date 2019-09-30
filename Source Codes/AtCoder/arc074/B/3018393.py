import heapq
N=int(input())
a=[int(i) for i in input().split()]
#ans[i]-> k=i+N,
red=[0 for i in range(N+1)]
blue=[0 for i in range(N+1)]
r=list(a[:N])
b=list([-i for i in a[2*N:]])
heapq.heapify(r)
heapq.heapify(b)
red[0]=sum(a[:N])
for i in range(N):
    k=i+N
    tmp1=a[k]
    heapq.heappush(r,a[k])
    tmp2=heapq.heappop(r)
    red[i+1]=red[i]-tmp2+tmp1
blue[-1]=sum(a[2*N:])
for i in range(N)[::-1]:
    k=i+N
    tmp1=a[k]
    heapq.heappush(b,-a[k])
    tmp2=-heapq.heappop(b)
    blue[i]=blue[i+1]-tmp2+tmp1
ans=[red[i]-blue[i] for i in range(N+1)]
print(max(ans))