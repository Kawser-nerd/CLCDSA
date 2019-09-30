import sys

N = int(input())

steps = []
for i in range(N):
    t, x, y = map(int, input().split())
    steps.append([t, x, y])

prev = [0, 0, 0]
for step in steps:
    t, x, y = step
    diff = abs(x - prev[1]) + abs(y - prev[2])
    time = t - prev[0]
    if diff > time or (time - diff) % 2 > 0:
        print('No')
        sys.exit()
    prev = [t, x, y]

print('Yes')