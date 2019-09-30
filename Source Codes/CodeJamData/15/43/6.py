# can be found here https://github.com/coin-or/pulp
from pulp import *

tc = int(input().strip())

for t in range(tc):
    n = int(input().strip())

    sen = []
    wor = dict()

    prob = LpProblem("myProblem", LpMinimize)

    for i in range(n):
        ws = input().split()
        s_e = LpVariable("s_%i^E" % i, 0, 1)
        s_f = LpVariable("s_%i^F" % i, 0, 1)
        sen.append((s_e, s_f))
        prob += s_e + s_f >= 1
        for w in ws:
            w_e, w_f = wor.setdefault(w, (LpVariable("w^E.%s" % w, 0, 1), LpVariable("w^F.%s" % w, 0, 1)))
            prob += w_e >= s_e
            prob += w_f >= s_f

    prob += sen[0][0] == 1
    prob += sen[1][1] == 1

    prob += lpSum(a[0] + a[1] for a in wor.values()) - len(wor)

    prob.solve()

    print("Case #%d: %0.0f" % (t+1, value(prob.objective)))

