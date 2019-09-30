from itertools import combinations


b_list = [[int(elem) for elem in input().split()] for _ in range(2)]
c_list = [[int(elem) for elem in input().split()] for _ in range(3)]
assert len(b_list[0]) == 3
assert len(c_list[0]) == 2


def adj(grid, turn):
    for i in range(9):
        if grid[i] == -1:
            next_grid = list(grid)
            next_grid[i] = turn
            yield tuple(next_grid)


def calc_value(final_grid, b_list, c_list):
    value = 0
    for i in range(2):
        for j in range(3):
            if final_grid[i * 3 + j] != -1 and final_grid[i * 3 + j] == final_grid[(i + 1) * 3 + j]:
                value += b_list[i][j]
    for i in range(3):
        for j in range(2):
            if final_grid[i * 3 + j] != -1 and final_grid[i * 3 + j] == final_grid[i * 3 + j + 1]:
                value += c_list[i][j]
    return value


memo = dict()
def dfs(grid, turn):
    if grid in memo:
        return memo[grid]
    else:
        if turn == 1:
            value =  max(dfs(next_grid, 0) for next_grid in adj(grid, turn))
        else:
            value =  min(dfs(next_grid, 1) for next_grid in adj(grid, turn))
        memo[grid] = value
        return value


for indices in combinations(range(9), r=5):
    final_grid = [0] * 9
    for i in indices:
        final_grid[i] = 1
    final_grid = tuple(final_grid)
    memo[final_grid] = calc_value(final_grid, b_list, c_list)


total_val = 0
for row in b_list:
    for item in row:
        total_val += item
for row in c_list:
    for item in row:
        total_val += item

chokudai = dfs(tuple([-1] * 9), 1)
naoko = total_val - chokudai
print(chokudai)
print(naoko)