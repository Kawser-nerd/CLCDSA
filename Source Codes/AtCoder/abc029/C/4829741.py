N = int(input())
ps_ls = []

def dfs(s):
    global ps_ls

    if len(s) == N:
        ps_ls.append(s)
        return

    dfs(s + 'a')
    dfs(s + 'b')
    dfs(s + 'c')

dfs('')

ps_ls = sorted(ps_ls)

for ps in ps_ls:
    print(ps)