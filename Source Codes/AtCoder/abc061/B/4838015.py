N, M = map(int, input().split())
roads = [0] * 60
for _ in range(M):
    for x in map(int, input().split()):
        roads[x] += 1
for i in range(1, N + 1):
    print(roads[i])