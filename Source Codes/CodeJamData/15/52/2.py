# can be found here https://github.com/coin-or/pulp
from pulp import *

tc = int(input().strip())

for t in range(tc):
    f = input().split()
    n, k = int(f[0]), int(f[1])

    # s_0 ... s_{n-k}
    s = [int(x) for x in input().strip().split()]

    var = [LpVariable("x_%d" % i, cat='Integer') for i in range(k-1)]
    for i in range(0, n-k+1):
        var.append(s[i] - sum(var[-(j+1)] for j in range(k-1)))

    prob = LpProblem("myProblem", LpMinimize)

    x_max = LpVariable("x_max")
    x_min = LpVariable("x_min")
    res = x_max - x_min
    
    for i in range(n):
        prob += x_max >= var[i]
        prob += x_min <= var[i]

    prob += res

    status = prob.solve()
    
    if status != 1:
        print("Case #%d: IMPOSSIBLE" % (t+1))
    else:
        print("Case #%d: %d" % (t+1, value(res)))

