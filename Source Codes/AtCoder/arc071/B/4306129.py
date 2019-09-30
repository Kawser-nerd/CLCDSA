mod = 10**9+7
n,m = map(int,input().split())	
x = list(map(int,input().split()))	
y = list(map(int,input().split()))
x.sort()
y.sort()

x_sum = 0
for i in range(1,n):
    x_sum += (x[i]-x[i-1])*i*(n-i)
    x_sum = x_sum%mod
y_sum = 0
for i in range(1,m):
    y_sum += (y[i]-y[i-1])*i*(m-i)
    y_sum = y_sum % mod
print(x_sum*y_sum%mod)