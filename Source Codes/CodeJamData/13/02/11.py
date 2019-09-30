def rotated(P):
    res = [[] for x in P[0]]
    for row in P:
        for j,x in enumerate(row):
            res[j].append(x)
    return res

def solve(P):
    rows = map(max, P)
    cols = map(max, rotated(P))
    for i,row in enumerate(P):
        for j,x in enumerate(row):
            if min(rows[i], cols[j]) > x:
                return "NO"
    return "YES"

t = input()
for testc in range(1,t+1):
    print 'Case #%d:' % testc,
    n,m = map(int,raw_input().split())
    P = [map(int,raw_input().split()) for i in range(n)]
    print solve(P)
