n, m, a, b = map(int, input().split())
c = [int(input()) for i in range(m)]

for i in range(m):
    if n <= a:
        n += b
    n -= c[i]
    if n < 0:
        print(i + 1)
        exit(0)
print('complete')