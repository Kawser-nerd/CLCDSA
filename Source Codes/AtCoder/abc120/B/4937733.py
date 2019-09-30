a, b, k = map(int, input().split())

res = []
for i in range(1, 101):
    if (a % i == 0) & (b % i == 0):
        res.append(i)

sorted(res)
print(res[-k])