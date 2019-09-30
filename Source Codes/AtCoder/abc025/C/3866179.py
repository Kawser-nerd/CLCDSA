b1 = list(map(int, input().split()))
b2 = list(map(int, input().split()))
c1 = list(map(int, input().split()))
c2 = list(map(int, input().split()))
c3 = list(map(int, input().split()))

from itertools import combinations


def adj(grid, turn):
    for i in range(9):
        if grid[i] == -1:
            next_grid = list(grid)
            next_grid[i] = turn
            yield tuple(next_grid)


def calc_value(points, b1, b2, c1, c2, c3):
    b_list = [b1, b2]
    c_list = [c1, c2, c3]
    value = 0
    for i in range(2):
        for j in range(3):
            if points[i * 3 + j] != -1 and points[i * 3 + j] == points[(i + 1) * 3 + j]:
                value += b_list[i][j]
    for i in range(3):
        for j in range(2):
            if points[i * 3 + j] != -1 and points[i * 3 + j] == points[i * 3 + j + 1]:
                value += c_list[i][j]
    return value


def dfs(grid, turn, memo):
    if grid in memo:
        return memo[grid]
    else:
        if turn == 1:
            value = max(dfs(next_grid, 0, memo) for next_grid in adj(grid, turn))
        else:
            value = min(dfs(next_grid, 1, memo) for next_grid in adj(grid, turn))
        memo[grid] = value
        return value


memo = dict()
for choku in combinations(range(9), 5):
    points = [0 for _ in range(9)]

    for c in choku:
        points[c] = 1
    points = tuple(points)
    memo[points] = calc_value(points, b1, b2, c1, c2, c3)
sum_num = sum(b1)
sum_num += sum(b2)
sum_num += sum(c1)
sum_num += sum(c2)
sum_num += sum(c3)

chokudai = dfs(tuple([-1] * 9), 1, memo)
naoko = sum_num - chokudai
print(chokudai)
print(naoko)