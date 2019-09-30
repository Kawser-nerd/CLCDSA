import sys
def ?():
    input = sys.stdin.readline
    W = int(input())
    N,K = [int(_) for _ in input().split()]
    dp={0:{0:0}}
    INF = float("inf")
    for i in range(N):
        w,v = [int(_) for _ in input().split()]
        if w <= W :
            for k in sorted(dp.keys(),reverse=True):
                if K <= k :
                    continue
                tk = k+1
                for j in dp[k]:
                    tv = j+v
                    tMin = min(dp.get(tk,{}).get(tv,INF),dp[k][j]+w)
                    if W < tMin:
                        continue
                    if tk in dp:
                        dp[tk][tv] = tMin
                    else:
                        dp[tk]={tv:tMin}
    print(max(max(ed.keys()) for ed in dp.values()))
?()