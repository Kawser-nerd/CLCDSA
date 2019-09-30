import pulp



def solve(J, P, S, K, Case):
    
    Js = range(J)
    Ps = range(P)
    Ss = range(S)
    
    # The prob variable is created to contain the problem data
    prob = pulp.LpProblem("Sudoku Problem", pulp.LpMaximize)

    # The problem variables are created
    x = pulp.LpVariable.dicts("x", (Js, Ps, Ss), 0, 1, pulp.LpInteger)

    # A constraint ensuring that only one value can be in each square is created
    for j in Js:
        for p in Ps:
            prob += pulp.lpSum([x[j][p][s] for s in Ss]) <= K, ""

    for s in Ss:
        for p in Ps:
            prob += pulp.lpSum([x[j][p][s] for j in Js]) <= K, ""

    for s in Ss:
        for j in Js:
            prob += pulp.lpSum([x[j][p][s] for p in Ps]) <= K, ""

    # The objective function is added
    prob += pulp.lpSum([x[j][p][s] for j in Js for p in Ps for s in Ss]), "Arbitrary Objective Function. We solve feasibility problem"

    prob.solve()

    obj = pulp.value(prob.objective)

    print "Case #{0}: {1}".format(Case, int(obj))
    # print solution
    for j in Js:
        for p in Ps:
            for s in Ss:
                val = pulp.value(x[j][p][s])
                if val == 1:
                    print j+1, p+1, s+1

    return obj

T=int(raw_input())+1

for tc in xrange(1,T):
    J, P, S, K = map(int, raw_input().split())
    solve(J, P, S, K, tc)
