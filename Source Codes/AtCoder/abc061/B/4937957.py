N, M = map(int, input().split())
ls = [list(map(int, input().split())) for _ in range(M)]

maps = {i:0 for i in range(1, N+1)}

for load in ls:
    maps[load[0]] += 1
    maps[load[1]] += 1

for i in range(1, N+1):
    print(maps[i])