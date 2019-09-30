H, W = map(int, input().split())
S = [list(input()) for i in range(H)]

memo = [[None] * W for i in range(H)]


def dfs(i, j):
    if i >= H or j >= W or S[i][j] == "#":
        return True

    if memo[i][j] is not None:
        return memo[i][j]

    win = False
    if not dfs(i+1, j): win=True
    if not dfs(i, j+1): win=True
    if not dfs(i+1, j+1): win=True

    memo[i][j] = win
    return win


print("First" if dfs(0, 0) else "Second")