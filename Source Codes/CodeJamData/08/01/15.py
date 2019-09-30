import sys

global engines
global memo
global queries

sys.setrecursionlimit(3500)

def best(s,q):
    
    #print "Best", s, q
    if (q<0):
        return (0, [])
    
    if (queries[q] == engines[s]):
        memo[(s,q)] = (2**30, []) 
        return (2**30, [])

    if ((s,q) in memo):
        return memo[(s,q)]
    
    themin = 2**30
    for i in range(len(engines)):
        if (s != i):
            cost = best(i,q-1)[0] + 1
        else:
            cost = best(i,q-1)[0]
        
        if (cost < themin):
            res = (cost, best(i,q-1)[1]+[s])
            themin = cost
            
    memo[(s,q)] = res
    return res

def findBest():
    themin = 2**30
    for i in range(len(engines)):
        cost = best(i,len(queries)-1)[0]
        if (cost < themin):
            themin = cost
            idx = i
    return best(idx,len(queries)-1)

f = open(sys.argv[1])

nCases = int(f.readline())

for j in range(nCases):
    memo = {}
    nEngines = int(f.readline())
    engines = []
    for i in range(nEngines):
         engines.append(f.readline().strip())
    nQueries = int(f.readline())
    queries = []
    for i in range(nQueries):
        queries.append(f.readline().strip())

    theBest = findBest()
    print "Case #%d: %d" % (j+1, theBest[0])
    #for i in range(len(queries)):
    #    print queries[i]," : ",engines[theBest[1][i]]  