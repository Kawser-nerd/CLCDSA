import sys

N, M = map(int, input().split())
ab = [tuple(map(int, line.split())) for line in sys.stdin.readlines()]

first = dict()
for a, b in ab:
    if a == 1:
        first[b] = 1

for a, b in ab:
    if b == N:
        if a in first:
            print("POSSIBLE")
            exit()

print('IMPOSSIBLE')