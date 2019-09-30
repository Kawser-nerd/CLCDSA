import sys

def compute(p, q, pris, memo, ends):
    if ends in memo:
        return memo[ends]

    rempris = [x for x in pris if x >= ends[0] and x <= ends[1]]
    if len(rempris) == 0:
        memo[ends] = 0
        return 0

    optimal = -1
    for x in rempris:
        val1 = compute(p, q, rempris, memo, (ends[0], x - 1))
        val2 = compute(p, q, rempris, memo, (x + 1, ends[1]))
        nval = (ends[1] - ends[0]) + val1 + val2
        if optimal == -1 or nval < optimal:
            optimal = nval

    memo[ends] = optimal
    return optimal


nt = int(sys.stdin.readline())
for it in range(1, nt+1):
    pq = sys.stdin.readline().split()
    pris = [int(x) for x in sys.stdin.readline().split()]

    p = int(pq[0])
    q = int(pq[1])

    memo = {}
    print "Case #%d: %d" % (it, compute(p, q, pris, memo, (1, p)))

