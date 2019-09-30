n = int(input())

if n <= 500:
    print(n)
    for i in range(n):
        print(' '.join([str(i+1)]*n))
    exit()

m = (n + 4 - 1) // 4 * 2
print(m)
for i in range(m):
    if i % 2 == 0:
        print(' '.join([str((i + j) % m % n + 1) for j in range(m)]))
    else:
        print(' '.join([str((m + (i + j) % m) + 1 if (m + (i + j) % m) < n else ((i + j) % m) + 1) for j in range(m)]))