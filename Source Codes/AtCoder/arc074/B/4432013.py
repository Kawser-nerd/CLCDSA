import heapq
n= int(input())
a=[int(i) for i in input().split()]
heap1=[]
heap2=[]
a_max=[]
b_max=[]
s=0
for i in range(n):
    heapq.heappush(heap1, a[i])
    s+=a[i]
a_max.append(s)
for i in range(n):
    heapq.heappush(heap1,a[n+i])
    mini=heapq.heappop(heap1)
    s=s+a[n+i]-mini
    a_max.append(s)
s=0
for i in range(n):
    heapq.heappush(heap2,-a[2*n+i])
    s=s-a[2*n+i]
b_max.append(s)    
for i in range(n):
    heapq.heappush(heap2,-a[2*n-1-i])
    mini=heapq.heappop(heap2)
    s=s-a[2*n-1-i]-mini
    b_max.append(s)
ans=a_max[0]+b_max[len(b_max)-1]
for i in range(n+1):
    res=a_max[i]+b_max[-(i+1)]
    ans=max(ans, res)
print(ans)