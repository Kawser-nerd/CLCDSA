N, M = map(int, input().split())

count = [0] * N
for _ in range(M):
    a, b = map(int, input().split())
    count[a - 1] += 1
    count[b - 1] += 1

for a in count:
    print(a)