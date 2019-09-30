n, m = map(int, input().split())
x = [0 for i in range(n)]
y = [0 for i in range(m)]
st = input().split()
for i in range(n):
    x[i] = int(st[i])
st = input().split()
for i in range(m):
    y[i] = int(st[i])

p = 10 ** 9 + 7

X = 0; Y = 0
for i in range(n):
    X += x[i]*(2*i-n+1)
    X = X % p
for i in range(m):
    Y += y[i]*(2*i-m+1)
    Y = Y % p

print((X*Y) % p)