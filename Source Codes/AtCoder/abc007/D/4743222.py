a,b=map(int,input().split())
def cnt(n):
    N=[int(x) for x in list(str(n))]
    digit=len(N)
    DP=[[0]*2 for _ in range(digit+1)]
    DP[0][0]=1
    for d in range(digit):
        for i in range(2):
            if i:
                limit=9
            else:
                limit=N[d]
            for l in range(limit+1):
                if l!=4 and l!=9:
                    DP[d+1][i or l<limit]+=DP[d][i]
    return n+1-DP[-1][0]-DP[-1][1]
print(cnt(b)-cnt(a-1))