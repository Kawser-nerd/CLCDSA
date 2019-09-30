#!/usr/bin/python

def solve(comb,opp,L):
    cur_l = []
    for i,s in enumerate(L):
        if len(cur_l) > 0:
            new = cur_l[-1] + s
            if new in comb:
                cur_l[-1] = comb[new]
                continue
            new = s + cur_l[-1] 
            if new in comb:
                cur_l[-1] = comb[new]
                continue
        if s in opp:
            seen = set(cur_l)
            if seen.intersection(opp[s]) != set({}):
                cur_l = []
                continue
        cur_l.append(s)
    return cur_l

def pp(L):
    return '[' + ', '.join(L) + ']'

r = input()
for i in range(1,r + 1):
    line = raw_input().split(' ')
    comb = {}
    opp = {}
    c = 0
    for j in range(int(line[c])):
        triple = line[j + c + 1]
        comb[triple[:2]] = triple[2]
    c = 1 + len(comb)
    for j in range(int(line[c])):
        pair = line[j + c + 1]
        opp[pair[0]] = opp.get(pair[0],set({})).union(pair[1])
        opp[pair[1]] = opp.get(pair[1],set({})).union(pair[0])
    L = line[-1]
    print "Case #%s: %s" % (i, pp(solve(comb,opp,L))) 
