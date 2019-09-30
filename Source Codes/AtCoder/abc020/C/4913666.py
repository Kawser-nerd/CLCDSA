from collections import defaultdict
from itertools import product
from math import pi
from collections import deque
INF = 10 ** 15


dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool:
    return 0 <= y < H and 0 <= x < W


def ok(sy: int, sx: int, gy: int, gx: int, field: list, x: int):
    q = deque()
    q.append((sy, sx, 0))

    memo = [[INF] * len(field[0]) for _ in range(len(field))]

    while len(q) != 0:
        now_y, now_x, now_t = q.popleft()

        # ?????
        for i in range(len(dy)):
            next_y, next_x = now_y + dy[i], now_x + dx[i]

            if inside(next_y, next_x, len(field), len(field[0])) and field[next_y][next_x] in (".", "#", "G"):
                next_t = now_t + (x if field[next_y][next_x] == "#" else 1)

                if next_t < memo[next_y][next_x]:
                    memo[next_y][next_x] = next_t
                    q.append((next_y, next_x, next_t))

    return memo[gy][gx]


def main():
    H, W, T = map(int, input().split())
    field = []
    sy, sx = None, None
    gy, gx = None, None
    for y in range(H):
        line = input()
        field.append(line)
        if "S" in line:
            sy, sx = y, line.index("S")
        if "G" in line:
            gy, gx = y, line.index("G")

    # [low, high)
    low, high, ans = -1, 10**10, -1
    while high - low > 1:
        middle = (low + high) // 2
        if ok(sy, sx, gy, gx, field, middle) <= T:
            ans = middle
            low = middle
        else:
            high = middle

    print(ans)


if __name__ == '__main__':
    main()