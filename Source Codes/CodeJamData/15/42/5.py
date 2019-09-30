inf = 1e111

def subok((R0, X0)):
    if abs(X0 - X) < 1e-8:
        return V / R0
    else:
        return inf

def subok2((R0, X0), (R1, X1)):
    if abs(X0 - X) < 1e-8 and abs(X1 - X) < 1e-8:
        return V / (R1 + R0)
    if abs(X0 - X) < 1e-8 or abs(X1 - X) < 1e-8:
        return inf
    if X0 >= X >= X1:
        return subok2((R1, X1), (R0, X0))
    if X0 <= X <= X1:
        W0 = X1 - X
        W1 = X - X0
        return V * max(W0 / R0, W1 / R1) / (X1 - X0)
    return inf

for cas in xrange(1,1+input()):
    N, V, X = raw_input().strip().split()
    N = int(N)
    V = float(V)
    X = float(X)

    src = []
    for i in xrange(N):
        Ri, Xi = map(float, raw_input().strip().split())

        src.append((Ri, Xi))

    ans = inf
    if N == 1:
        ans = min(ans, subok(src[0]))
    else:
        ans = min(ans, subok(src[0]))
        ans = min(ans, subok(src[1]))
        ans = min(ans, subok2(src[0],src[1]))

    print "Case #%s:" % cas,
    if ans > inf/2:
        print "IMPOSSIBLE"
    else:
        print "%.11f" % ans

        