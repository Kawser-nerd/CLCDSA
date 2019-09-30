from itertools import combinations

B = []
for _ in range(2):
    B.append(list(map(int, input().split())))
C = []
for _ in range(3):
    C.append(list(map(int, input().split())))


memo = dict()


def next_grid(grid, turn):
    """
    ???????
    ?????????-1
    """
    for i in range(9):
        if grid[i] == -1:
            next = list(grid)
            next[i] = turn
            yield(tuple(next))


def calc_score(grid):
    scoreT = 0
    scoreN = 0
    for i in range(2):
        for j in range(3):
            if grid[3*i+j] != -1 and grid[3*i + j] == grid[3*(i+1)+j]:
                scoreT += B[i][j]

    for i in range(3):
        for j in range(2):
            if grid[3*i+j] != -1 and grid[3*i+j] == grid[3*i+j+1]:
                scoreN += C[i][j]
    return scoreN+scoreT


def dfs(grid, turn):
    if grid in memo:
        return memo[grid]
    else:
        if turn == 1:
            value = max(dfs(next, 0) for next in next_grid(grid, turn))
        else:
            value = min(dfs(next, 1) for next in next_grid(grid, turn))
        memo[grid] = value
    return value


for final in combinations(range(9), 5):
    final_grid = [0]*9
    for i in final:
        final_grid[i] = 1
    final_grid = tuple(final_grid)
    memo[final_grid] = calc_score(final_grid)


total = sum([sum(l) for l in B])
total += sum([sum(l) for l in C])
init_grid = tuple(list([-1]*9))
scoreT = dfs(init_grid, 1)
scoreN = total-scoreT
print(scoreT)
print(scoreN)