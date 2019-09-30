import sys
sys.setrecursionlimit(100000)
import heapq
n=int(input())
data=[]
a=list(map(int,input().split()))
amax=0
for i in range(n):
    heapq.heappush(data,a[i])
    amax+=a[i]
ansdata=[amax]
for i in range(n,2*n):
    heapq.heappush(data,a[i])
    amax+=a[i]
    amax-=heapq.heappop(data)
    ansdata.append(amax)
data=[]
bmin=0
for i in range(2*n,3*n):
    heapq.heappush(data,-a[i])
    bmin+=a[i]
ansdata[-1]-=bmin
for i in range(n):
    t=i
    i=2*n-1-i
    heapq.heappush(data,-a[i])
    bmin+=a[i]
    bmin+=heapq.heappop(data)
    ansdata[-t-2]-=bmin

print(max(ansdata))