f = lambda: map(int,input().split())
n,_ = f()
a = list(f())
b = [a[0]]+[0]*(n-1)
for i in range(1,n):
    b[i] = min(a[i], b[i-1])
c = [a[i]-b[i] for i in range(n)]
m = max(c)
print(c.count(m))