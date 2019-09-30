# can be found here https://github.com/coin-or/pulp
from pulp import *

tc = int(input().strip())

for t in range(tc):
    f = input().split()
    n, v, x = int(f[0]), float(f[1]), float(f[2])

    m = n * [[]]
    for i in range(n):
        m[i] = tuple(float(a) for a in input().split())

    var = [LpVariable("%d" % i, 0) for i in range(n)]
    res = LpVariable("r", 0)

    prob = LpProblem("myProblem", LpMinimize)
    
    for i in range(n):
        prob += res >= var[i]

    prob += lpSum(m[i][0] * var[i] for i in range(n)) == v
    prob += lpSum(m[i][0] * m[i][1] / v * var[i] for i in range(n)) == x

    prob += res

    status = prob.solve()
    
    if status != 1:
        print("Case #%d: IMPOSSIBLE" % (t+1))
    else:
        print("Case #%d: %0.8f" % (t+1, value(res)))

