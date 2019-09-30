
def StockCharts():
    global M, C, n, best
    n, k = map(int, raw_input().split())
    prices = []
    for i in range(n):
        prices.append(map(int, raw_input().split()))
    M = [0] * n
    for i in range(n):
        for j in range(i+1, n):
            d1 = prices[i][0] - prices[j][0]
            for t in range(1, k):
                d2 = prices[i][t] - prices[j][t]
                if d1*d2 <= 0:
                    M[i] |= 1<<j
                    M[j] |= 1<<i
                    break
    C = [0] * n
    best = n
    go(0, 0)
    print best

def go(s, c):
    global M, C, n, best
    if c >= best:
        return
    if s == n:
        best = c
        return
    for i in range(c+1):
        if (1<<s) & C[i]:
            continue
        p = C[i]
        C[i] |= M[s]
        go(s+1, c+(i==c))
        C[i] = p

#---------------------------------------------------------------

T = int(raw_input())
for testcase in range(T):
    print "Case #%d:" % (testcase+1),
    StockCharts()
