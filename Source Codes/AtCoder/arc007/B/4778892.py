N, M = [int(_) for _ in input().split()]
disk = [int(input()) for i in range(M)]

result = [(i + 1) for i in range(N)]

n = 0
for d in disk:
    if d != n:
        i = result.index(d)
        result[i], n = n, d

for i in range(N):
    print(result[i])