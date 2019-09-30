def dfs(q,x):
    global n,k,t
    if q==n:
        if x == 0:
            return True
        else:
            return False
    for i in range(k):
        if dfs(q+1,x^t[q][i]):
            return True
    return False

n,k = map(int, input().split())
t = [list(map(int,input().split())) for _ in range(n)]
if dfs(0,0):
    print("Found")
else:
    print("Nothing")