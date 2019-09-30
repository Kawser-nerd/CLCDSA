import sys
sys.setrecursionlimit(10**8)
N=int(input())
P=[int(i) for i in input().split()]
X=[int(i) for i in input().split()]
table=[[] for i in range(N)]
for i in range(N-1):
    table[P[i]-1].append(i+1)
dp=[0]*N #shiro

def tree(pa):
    for i in table[pa]:
        tree(i)
    t=len(table[pa])
    if t==0:
        return
    T=set()
    s=0
    for i in range(t):
        x=table[pa][i]
        s+=X[x]+dp[x]
        if i==0:
            if X[x]<=X[pa]:
                T.add(X[x])
            if dp[x]<=X[pa]:
                T.add(dp[x])
            continue
        S=set()
        for k in T:
            if k+X[x]<=X[pa]:
                S.add(k+X[x])
            if k+dp[x]<=X[pa]:
                S.add(k+dp[x])
        T=S
    if len(T)==0:
        print('IMPOSSIBLE')
        sys.exit()
    dp[pa]=s-max(T)
    return

tree(0)    
print('POSSIBLE')