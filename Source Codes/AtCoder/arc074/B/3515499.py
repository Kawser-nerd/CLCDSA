N = int(input())
a = [int(i) for i in input().split()]

import heapq

front = [a[i] for i in range(N)]
heapq.heapify(front)
middle = list(a[N:2*N])
back = list(a[2*N:3*N])

sumfront = [0 for _ in range(N+1)]
sumfront[0] = sum(list(a[0:N]))
for i in range(1,N+1):
    sumfront[i] = sumfront[i-1] + middle[i-1] \
    - heapq.heappushpop(front,middle[i-1]) 

minusmiddle = [-1*middle[i] for i in range(N)]
minusback = [-1*a[i+2*N] for i in range(N)]
heapq.heapify(minusback)
sumback = [0 for _ in range(N+1)]
sumback[N] = -1*sum(list(a[2*N:3*N]))
for i in range(N-1,-1,-1):
    sumback[i] = sumback[i+1] + minusmiddle[i] - heapq.heappushpop(minusback,minusmiddle[i])

ans = -1*float('inf')
for i in range(N+1):
    ans = max(ans,sumfront[i] + sumback[i])
print(ans)