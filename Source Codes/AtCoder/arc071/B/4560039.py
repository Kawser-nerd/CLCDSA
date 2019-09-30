mod = 10**9+7
n,m = map(int, input().split())
x = sorted(map(int, input().split()))
y = sorted(map(int, input().split()))
x = [i-x[0] for i in x]
y = [i-y[0] for i in y]
sumx = sum(x)
sumy = sum(y)
allx = sumx
ally = sumy
for i in range(1,n):
    sumx -= (n-i)*(x[i]-x[i-1])
    allx = (allx+sumx)%mod
for i in range(1,m):
    sumy -= (m-i)*(y[i]-y[i-1])
    ally = (ally+sumy)%mod
print(allx*ally%mod)