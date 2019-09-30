def cost(en,fr):
    return len(en & fr)


def greedy(en,fr,other):
    # calculate a sub-optimal greedy solution to use as initial best in solve()
    all_words = set()
    all_words |= en
    all_words |= fr
    for o in other:
        all_words |= o
    
    total = len(all_words)
    gen = set(en)
    gfr = set(fr)
    
    for o in other:
        nen = gen | o
        nfr = gfr | o
        cen = len(nen) - len(gen)
        cfr = len(nfr) - len(gfr)
        if cen < cfr:
            gen = nen
        else:
            gfr = nfr
    
    return solve(en,fr,other,len(gen&gfr))
    
    
def solve(en,fr,other,best=None):
    if len(other) == 0:
        return len(en & fr)
    if best != None and len(en&fr) > best:
        return best
    
    sub_en = en | other[0]
    sub_fr = fr | other[0]
    sub_other = other[1:]
    
    s0 = solve(sub_en,fr,sub_other,best)
    s1 = solve(en,sub_fr,sub_other,best)
    
    if s0 == None or s1 == None:
        print "??????"
    
    return min(s0,s1)
    

n_cases = input()
for case in range(1,n_cases + 1):
    n = input()
    en = raw_input().split(' ')
    fr = raw_input().split(' ')
    other = map(set,[raw_input().split(' ') for _ in range(n-2)])
    
    solution = greedy(set(en),set(fr),other)
    print "Case #%d: %s" % (case,solution)