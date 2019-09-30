N, M = map(int, input().rstrip().split())
ab = [list(map(int, input().rstrip().split())) for _ in range(M)]
count = [[0]*N for _ in range(N)]
for road in ab:
    count[road[0]-1][road[1]-1] += 1
    count[road[1]-1][road[0]-1] += 1
for i in range(N):
    print(sum(count[i]))