n, x = map(int, input().split())
total = n
a = x
b = n - x
while a > 0:
    total += (a * 2) * (b // a)
    a, b = b % a, a
print(total - b)