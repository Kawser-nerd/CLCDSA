N = int(input())

def dfs(x):
    if x > 100:
        return 0
    cnt = 1 if x == N else 0
    cnt += dfs(x+4)
    cnt += dfs(x+7)
    return cnt

print('Yes' if dfs(0) >= 1 else 'No')