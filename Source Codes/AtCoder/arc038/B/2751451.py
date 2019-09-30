H, W = map(int, input().split())
S = [list(input()) for i in range(H)]
memo = [[None] * W for i in range(H)]


def dfs(x, y):
    global memo
    if y >= H or x >= W or S[y][x] == "#":
        return True

    if memo[y][x] is not None:
        return memo[y][x]

    result = False
    if not dfs(x+1, y): result = True
    if not dfs(x, y+1): result = True
    if not dfs(x+1, y+1): result = True
    memo[y][x] = result
    return result


print("First" if dfs(0, 0) else "Second")