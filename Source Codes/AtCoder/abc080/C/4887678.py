import sys
sys.setrecursionlimit(10000)

N=int(input())
count=[]
F=[list(map(int,input().split())) for i in range(N)]
P=[list(map(int,input().split())) for i in range(N)]
INF=10**9

def dfs(s):
    if len(s)==10:
        if "1" not in s:
            val=-INF
        if "1" in s:
            val=0
            c=[0 for i in range(N)]
            for i in range(N):
                #F1 F2
                count=0
                for j in range(10):
                    
                    if int(int(s[j])*F[i][j]):
                        c[i]+=1
                    #print("count",count)

            for i in range(N):
                val+=P[i][c[i]]
        return val
    else:
        return max(dfs(s+"0"),dfs(s+"1"))
print(dfs(""))