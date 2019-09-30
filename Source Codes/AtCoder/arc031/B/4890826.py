M = [list(input()) for _ in range(10)]

def dfs(m, x, y):
    for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        if 0 <= x + dx < 10 and 0 <= y + dy < 10:
            if m[y + dy][x + dx] == 'o':
                m[y + dy][x + dx] = 'x'
                dfs(m, x + dx, y + dy)

def island(m, x, y):
    dfs(m, x, y)
    return all(all(x == 'x' for x in l) for l in m)

def solve():
    for y in range(10):
        for x in range(10):
            if M[y][x] == 'x':
                M2 = [l[:] for l in M]
                if island(M2, x, y):
                    return True

print('YES' if solve() else 'NO')