a, b, c, K = map(int, open(0).read().split())
m = max(a, b, c)
print(m*2**K+a+b+c-m)