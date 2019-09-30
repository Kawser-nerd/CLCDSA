N, M, A, B = [int(_) for _ in input().split()]
c = [int(input()) for i in range(M)]

result = "complete"
x = N
for i in range(M):
    if x <= A:
        x += B
    x -= c[i]
    if x < 0:
        result = i + 1
        break

print(result)