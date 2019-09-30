N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
C_map = [list(map(int, input().split())) for _ in range(N)]

#??????????Index???-1??
for y in range(N):
    for x in range(N):
        C_map[y][x] -= 1

#
col_lines = [[0 for _ in range(C)] for _ in range(3)]
for y in range(N):
    for x in range(N):
        idx = (x + y) % 3
        col_lines[idx][C_map[y][x]] += 1

# ?????C???????????????????
def calc_cost(line, target_color):
    cost = 0
    for col, count in enumerate(line):
        cost += D[col][target_color] * count
    return cost

#[cost, ?] ????
costs = [[0 for _ in range(C)] for _ in range(3)]
for i in range(3):
    for c in range(0, C):
        costs[i][c] = [calc_cost(col_lines[i], c), c]
    costs[i].sort(key=lambda x: x[0])

# ????????i1, i2, i3 ??costs?Index
# ?????????Index???????????????OK
def find_min(i1, i2, i3):
    if i1 >= 3 or i2 >= 3 or i3 >= 3: #3???????4????????????
        return 100000000000000

    line1 = costs[0]
    line2 = costs[1]
    line3 = costs[2]
    if i1 >= len(line1) or i2 >= len(line2) or i3 >= len(line3):
        return 1000000000000
    c1 = line1[i1][1]
    c2 = line2[i2][1]
    c3 = line3[i3][1]
    if c1 == c2 and c1 == c3:
        return min(
            find_min(i1 + 1, i2, i3),
            find_min(i1, i2 + 1, i3),
            find_min(i1, i2, i3 + 1)
        )
    if c1 == c2:
        return min(
            find_min(i1 + 1, i2, i3),
            find_min(i1, i2 + 1, i3),
        )
    if c1 == c3:
        return min(
            find_min(i1 + 1, i2, i3),
            find_min(i1, i2, i3 + 1)
        )
    if c2 == c3:
        return min(
            find_min(i1, i2 + 1, i3),
            find_min(i1, i2, i3 + 1)
        )
    return line1[i1][0] + line2[i2][0] + line3[i3][0]

print(find_min(0, 0, 0))