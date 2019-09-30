from queue import deque
from math import ceil

h, w, k = map(int, input().split())

rooms = [None] * h
for i in range(h):
    row = input().strip()
    rooms[i] = row
    if 'S' in row:
        s = (i, row.index('S'))


def generate_neighbors(i, j):
    for ni, nj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
        if rooms[ni][nj] == '.':
            yield ni, nj


def get_dist_to_exit(i, j):
    return min(i, h - i - 1, j, w - j - 1)


def first_bws():
    visited = {s}
    queue = deque((1, ij) for ij in generate_neighbors(*s))
    min_exit = get_dist_to_exit(*s)
    while queue:
        dist, ij = queue.popleft()
        if dist > k:
            break
        if ij in visited:
            continue
        i, j = ij
        tmp_min_exit = get_dist_to_exit(i, j)
        if tmp_min_exit == 0:
            return 0
        min_exit = min(min_exit, tmp_min_exit)
        visited.add(ij)
        queue.extend((dist + 1, nij) for nij in generate_neighbors(i, j) if nij not in visited)
    return min_exit


dist_to_exit = first_bws()
print(ceil(dist_to_exit / k) + 1)