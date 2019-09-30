import sys


def solve(obstacles):
    offset = 0
    obstacles.sort()
    for x, y in obstacles:
        if x > y + offset:
            return x - 1
        if x == y + offset:
            offset += 1
    return h


h, w, n = map(int, input().split())
obstacles = [tuple(map(int, line.split())) for line in sys.stdin.readlines()]
print(solve(obstacles))