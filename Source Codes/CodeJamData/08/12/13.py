import re, sys
def solve(N, customers):
    malthash = [0 for flavor in xrange(0,N+1)]
    #customers.sort(cmp=lambda x,y: cmp(len(x), len(y)))
    
    
    def iterate():
        satisfied = True
        for i in xrange(len(customers)):
            c = customers[i]
            if len(c) == 0:
                return "IMPOSSIBLE"
            if (len(c) == 1 and 
            malthash[c[0][0]] == 0 and 
            c[0][1] == 1):
                satisfied = False
                malthash[c[0][0]] = 1
                for cust in customers:
                    try:
                        cust.remove((c[0][0],0))
                    except:
                        pass
        if satisfied:
            return malthash[1:]
        else:
            return iterate()
                        
    return iterate()
                    
def parse_input():
    if len (sys.argv) < 2:
        print "Enter an input filename please"
        return
    inp = open (sys.argv[1])

    lines = [re.sub(r'[\n\r]','',l) for l in inp.readlines()]
    num_cases = int(lines[0])
    line_num = 1
    for case in xrange(num_cases):
        N = int(lines[line_num])
        M = int(lines[line_num+1])
        line_num += 2
        customers = []
        for p in xrange(M):
            line = lines[line_num].split()
            num_pairs = int(line[0])
            pairs = []
            for n in xrange(num_pairs):
                pairs.append((int(line[2*n+1]),int(line[2*n+2])))
            customers.append(pairs)
            line_num += 1
        soln = solve(N, customers)
        if type(soln) == type(""):
            print "Case #"+str(case+1)+":", soln
        else:
            print "Case #"+str(case+1)+":",
            for i in soln:
                print i,
            print

parse_input()