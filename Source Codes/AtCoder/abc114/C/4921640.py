N = int(input())

cnt = 0
def dfs(s):
    global cnt
    if '3' in s and '5' in s and '7' in s and int(s) <= N:
        cnt += 1
    if len(s) >= 10:
        return cnt
    dfs(s + '3')
    dfs(s + '5')
    dfs(s + '7')
    return cnt

print(dfs(''))