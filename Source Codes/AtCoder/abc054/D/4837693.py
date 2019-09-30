def main():
    n,ma,mb = map(int, input().split())
    a,b,c = [],[],[]
    for i in range(n):
        ia,ib,ic = map(int, input().split())
        a.append(ia)
        b.append(ib)
        c.append(ic)
    sa = sum(a)
    sb = sum(b)
    INF = 10**5
    dp = [[ [INF] * (sb+1) for i in range(sa+1)] for i in range(n+1)]
    dp[0][0][0] = 0

    for i in range(n):
        for ca in range(sa):
            for cb in range(sb):
                if dp[i][ca][cb] == INF:
                    continue
                dp[i+1][ca][cb] = min(dp[i+1][ca][cb], dp[i][ca][cb])
                dp[i+1][ca+a[i]][cb+b[i]] = min(dp[i+1][ca+a[i]][cb+b[i]], dp[i][ca][cb] + c[i])



    res = INF
    for ca in range(1, sa):
        for cb in range(1, sb):
            if ca*mb==cb*ma:
                res = min(res, dp[n][ca][cb])

    if res == INF:
        res = -1
    print(res)

if __name__ == '__main__':
    main()