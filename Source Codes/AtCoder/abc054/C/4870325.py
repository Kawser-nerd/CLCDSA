N,M = map(int,input().split())
dict = {}
for m in range(M):
    a,b = map(int,input().split())
    if a in dict:
        dict[a].append(b)
    else:
        dict[a] = [b]
    if b in dict:
        dict[b].append(a)
    else:
        dict[b] = [a]
ans = 0
l = [0 for i in range(N+1)]
l[1] = 1
def dfs(l,now):
    global ans
    if sum(l) == N:
        ans += 1
        return(0)
    for i in dict[now]:
        if l[i] == 0:
            l[i] += 1
            now = i
            dfs(l,now)
            l[i] -= 1
        else:
            continue
dfs(l,1)
print(ans)