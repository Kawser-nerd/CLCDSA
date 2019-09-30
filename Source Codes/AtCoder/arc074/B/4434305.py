import heapq

n = int(input())
a = list(map(int,input().split()))


h1 = []
sum1 = [0]
for i in range(n):
    sum1[0] += a[i] 
    heapq.heappush(h1,a[i])

for i in range(n,2*n):
    sum = sum1[i-n]
    aa = heapq.heappop(h1)
    if (aa < a[i]):
        heapq.heappush(h1,a[i])
        sum += (a[i] - aa)
    else:
        heapq.heappush(h1,aa)
    sum1.append(sum)

h2 = []
sum2 = [0]
for i in range(n):
    sum2[0] -= a[3*n-i-1] 
    heapq.heappush(h2,-1 * a[3*n-i-1])

for i in range(n,2*n):
    sum = sum2[i-n]
    aa = heapq.heappop(h2)
    if (aa < -1 * a[3*n - i-1]):
        heapq.heappush(h2,-1 * a[3*n - i-1])
        sum += (-1 * a[3*n - i-1] - aa)
    else:
        heapq.heappush(h2,aa)
    sum2.append(sum)


ans = - 10 ** 15
for i in range(n+1):
    ans = max(ans,sum1[i]+sum2[n-i])

print(ans)