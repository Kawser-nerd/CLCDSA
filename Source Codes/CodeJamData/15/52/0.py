import pulp

MAX = 1e8

def solve(ca):
    n, k = map(int, raw_input().split())
    problem = pulp.LpProblem('pname', pulp.LpMinimize)

    sumi = map(int, raw_input().split())

    xi = [pulp.LpVariable('x%d'%i, -MAX, MAX, 'Integer') for i in range(n)]
    #linex = [pulp.LpVariable('li%d'%i, 0, 1, 'Binary') for i in range(n)]
    maxx = pulp.LpVariable('maxx', -MAX, MAX, 'Integer')
    minx = pulp.LpVariable('minx', -MAX, MAX, 'Integer')    
    problem += pulp.lpSum([xi[i] for i in range(k)]) == sumi[0]

    for i in range(n - k):
        problem += sumi[i] + xi[i + k] == sumi[i + 1] + xi[i]
    for i in range(n):
        problem += xi[i] <= maxx
        problem += xi[i] >= minx

    problem += maxx - minx
    
    #print problem
    #status = problem.solve(pulp.GLPK())
    #status = problem.solve(pulp.COIN(msg = True))
    status = problem.solve(pulp.COIN())    
    #status = problem.solve()
    
    ans = maxx.value() - minx.value()
    
    # for i in linex:
    #     print i, i.value(),
    # print
    print "Case #%d: %.0f"%(ca, ans)
    #exit()
    
for i in range(int(raw_input())):
    solve(i + 1)
