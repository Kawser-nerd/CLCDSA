import heapq
n = int(input())
a = list(map(int,input().split()))

FN = []
SN = []
for i in range(n):
    FN.append(a[i])
for i in range(2*n,3*n):
    SN.append(-a[i])
heapq.heapify(FN)
heapq.heapify(SN)


sumFN = [0]*(n+1)
sumSN = [0]*(n+1)
sumFN[0] = sum(FN)
sumSN[n] = -sum(SN)

for i in range(1,n+1):
    k = 0
    k += a[n-1+i]
    heapq.heappush(FN,a[n-1+i])
    k -= heapq.heappop(FN)
    sumFN[i] = sumFN[i-1]+k

for i in range(n-1,-1,-1):
    k = 0
    k += a[n+i]
    heapq.heappush(SN,-a[n+i])
    k -= -heapq.heappop(SN)
    sumSN[i] = sumSN[i+1]+k

res = sumFN[0]-sumSN[0]
for i in range(n+1):
    res = max(res,sumFN[i]-sumSN[i])
print(res)