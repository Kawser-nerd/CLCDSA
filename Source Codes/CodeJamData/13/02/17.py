tcou = input()
for tnum in range(tcou):
    n, m = [int(x) for x in raw_input().split()]
    tbl = [[int(x) for x in raw_input().split()] for _ in range(n)]
    good = {(i, j): False for i in range(n) for j in range(m)}
    for i in range(n):
        M = max(tbl[i])
        for j in range(m):
            if tbl[i][j]==M:
                good[i, j] = True
    for j in range(m):
        M = max([tbl[i][j] for i in range(n)])
        for i in range(n):
            if tbl[i][j]==M:
                good[i, j] = True
    print "Case #%d: %s"%(tnum+1, "NO" if False in good.values() else "YES")
