n,m = map(int,input().split())
mod = 1000000007
x = list(map(int,input().split()))
y = list(map(int,input().split()))
xa = 0
ya = 0
for i in range(m):
  ya += (i)*y[i] -(m-i-1) *y[i]
for i in range(n):
  xa += (i)*x[i] -(n-i-1) *x[i]
print(ya*xa%mod)