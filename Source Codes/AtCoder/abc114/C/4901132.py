N= int(input())


def dfs(s):
    if int(s) > N:
        return 0
    if all(s.count(c) > 0 for c in '753'):
        ret = 1
    else:
        ret = 0
    for c in '753':
        ret += dfs(s + c)
    return ret


print(dfs('0'))