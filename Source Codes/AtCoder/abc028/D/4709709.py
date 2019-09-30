n, k = map(int, input().split())
a = k - 1
b = n - k
print((a*b*6 + a*3 + b*3 + 1) / n**3)