N,K = map(int,input().split())
tNK = []
for i in range(N):
    tNK.append(list(map(int,input().split())))

def dfs(numq,value):
    if numq == N:
        return True if value == 0 else False
    for i in range(K):
        if dfs(numq+1,value^tNK[numq][i]):
            return True
    return False
    
if dfs(0,0):
    print("Found")
else:
    print("Nothing")