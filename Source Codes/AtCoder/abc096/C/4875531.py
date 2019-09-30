import sys
input = sys.stdin.readline
from itertools import product

H, W = map(int, input().split())
maps = [['.']*(W+2)] + [(['.'] + list(input()) + ['.']) for _ in range(H)] + [['.']*(W+2)]
dxy = ((0, -1), (0, 1), (-1, 0), (1, 0))

for i, j in product(range(1, H+1), range(1, W+1)):
    if maps[i][j] == '#':
        for k, l in dxy:
            if maps[i+k][j+l] == '#':
                break
        else:
            print("No")
            exit()

print("Yes")