import sys

H, W, D = map(int, input().split())
a = [list(map(int, l.split())) for l in sys.stdin]

ans = max(max(row[to_x%2:to_x+1:2]) for to_x, row in zip(range(D, -1, -1), a[:D+1]))
print(ans)