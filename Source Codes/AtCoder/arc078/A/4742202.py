n = int(input())
a = list(map(int, input().split()))
sums=[0 for i in range(n)]
sums[0]=a[0]
for i in range(1,n):
    sums[i] = sums[i-1]+a[i]

res=[0 for i in range(n-1)]

for i in range(0,n-1):
    res[i] = abs(2*sums[i]-sums[-1])
        
print(min(res))