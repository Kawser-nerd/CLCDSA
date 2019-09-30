A, B = map(int, input().split())
count = 0
for i in range(10):
    for j in range(10):
        for k in range(10):
            n = 10000 * i + 1000 * j + 100 * k + 10 * j + i
            if A <= n <= B:
                count += 1
print(count)