n, k = map(int,input().split())
c = 0.000000
rates = list(map(int,input().split()))

rates.sort()
del rates[:(n-k)]
for i in rates:
    c = (c + i) / 2

print(c)