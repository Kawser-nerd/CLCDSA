N = int(input())
ans = []

def dfs(s):
    global ans
    if len(s) == N:
        ans.append(s)
        return

    for c in 'abc':
        dfs(s + c)

dfs('')
for i in ans:
    print(i)