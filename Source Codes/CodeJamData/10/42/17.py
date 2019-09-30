
def calc( M, cost ):
    if len(cost) == 1:
        if min(M) > 0:
            return 0
        else:
            return cost[0][0]
    
    LM, RM = M[:len(M)/2], M[len(M)/2:]
    
    Lcost, Rcost = [], []
    for cst in cost[:-1]:
        Lcost += [cst[:len(cst)/2]]
        Rcost += [cst[len(cst)/2:]]
    
    val2 = cost[-1][0] + calc(LM, Lcost) + calc(RM, Rcost)
    
    val1 = 9999999999
    if min(M) > 0:
        M = map((lambda x: x-1), M)
        LM, RM = M[:len(M)/2], M[len(M)/2:]
        val1 = calc(LM, Lcost) + calc(RM, Rcost)
    return min(val1, val2)


T = int(raw_input())
for c in range(T):
    P = int(raw_input())
    M = map(int, raw_input().split())
    cost = []
    for p in range(P):
        v = map(int, raw_input().split())
        cost += [v]
    #print M
    #print cost
    
    print "Case #%d: %d" % (c+1, calc(M, cost))