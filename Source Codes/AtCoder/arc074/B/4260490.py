import heapq
n = int(input())
a = list(map(int,input().split()))

first = []
second = []
for i in range(n):
    first.append(a[i])
for i in range(2*n,3*n):
    second.append(-a[i])
heapq.heapify(first)
heapq.heapify(second)


sumfirst = [0]*(n+1)
sumsecond = [0]*(n+1)
sumfirst[0] = sum(first)
sumsecond[n] = -sum(second)

for i in range(1,n+1):
    k = 0
    k += a[n-1+i]
    heapq.heappush(first,a[n-1+i])
    k -= heapq.heappop(first)
    sumfirst[i] = sumfirst[i-1]+k

for i in range(n-1,-1,-1):
    k = 0
    k += a[n+i]
    heapq.heappush(second,-a[n+i])
    k -= -heapq.heappop(second)
    sumsecond[i] = sumsecond[i+1]+k

res = sumfirst[0]-sumsecond[0]
for i in range(n+1):
    res = max(res,sumfirst[i]-sumsecond[i])
print(res)