a, b, c, K = map(int, input().split())

res = 'Unfair'
if K % 2 == 0:
    if abs(a - b) <= 10 ** 18:
        res = a - b
else:
    if abs(a - b) <= 10 ** 18:
        res = b - a
print(res)