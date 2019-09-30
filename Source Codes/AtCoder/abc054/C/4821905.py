N,M = map(int,input().split())
edge_list = [list() for i in range(N)]
for i in range(M):
        a,b = map(int,input().split())
        edge_list[a-1].append(b-1)
        edge_list[b-1].append(a-1)
done = [0] * N
chk = 0
def dfs(s,done):
    done = done[:]
    global chk
    done[s] = True
    if all(done):
        chk += 1
    for i in edge_list[s]:
        if not done[i]:
            dfs(i,done)
    return 0
dfs(0,done)
print(chk)