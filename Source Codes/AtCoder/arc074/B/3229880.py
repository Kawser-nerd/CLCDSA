import heapq
import bisect

n = int(input())
n = n*3
a = list(map(int,input().split()))

left = a[0:n//3]
right = list(-i for i in a[2*n//3:])

leftsum = [0 for i in range(n//3+1)]
rightsum = [0 for i in range(n//3+1)]

heapq.heapify(left)
leftsum[0] = sum(left)
for i in range(n//3):
    k = i + n//3
    heapq.heappush(left,a[k])
    temp = heapq.heappop(left)
    leftsum[i+1] = leftsum[i]+a[k]-temp

heapq.heapify(right)
rightsum[-1] = -sum(right)
for i in range(n//3)[::-1]:
    k = i + n//3
    heapq.heappush(right,-a[k])
    temp = -heapq.heappop(right)
    rightsum[i] = rightsum[i+1] - temp + a[k]




mxm = -sum(a)
for i in range(n//3+1):
    if leftsum[i]-rightsum[i] > mxm:
        mxm = leftsum[i]-rightsum[i]
print(mxm)