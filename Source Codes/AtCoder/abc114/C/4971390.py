n = int(input())


def dfs(s):
    if s and int(s) > n:
        return 0
    if '3' in s and '5' in s and '7' in s:
        return dfs(s + '3') + dfs(s + '5') + dfs(s + '7') + 1
    else:
        return dfs(s + '3') + dfs(s + '5') + dfs(s + '7')


print(dfs(''))