import sys
N, M = map(int, input().split())
a = [list(map(int, l.rstrip())) for l in sys.stdin]
result = [[0]*M for _ in [0]*N]

for y in range(1, N-1):
    for x in range(1, M-1):
        v = min(a[y-1][x], a[y][x+1], a[y+1][x], a[y][x-1])
        a[y-1][x] -= v
        a[y][x+1] -= v
        a[y+1][x] -= v
        a[y][x-1] -= v
        result[y][x] = v

print(*("".join(map(str, l)) for l in result), sep="\n")