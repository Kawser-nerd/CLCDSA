def inpl(): return [int(i) for i in input().split()]
mod = 10**9+7

n, m = inpl()
x = inpl()
y = inpl()
H = [(x[i+1]-x[i])*(i+1)*(n-i-1) % mod for i in range(n-1)]
W = [(y[j+1]-y[j])*(j+1)*(m-j-1) % mod for j in range(m-1)]

print(sum(H)*sum(W) % mod)