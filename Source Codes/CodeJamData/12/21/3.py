# -*- coding: utf-8 -*-
# <nbformat>3</nbformat>

# <codecell>

def readline_ints():
    return [int(num) for num in fin.readline().strip().split()]

# <codecell>

from collections import Counter
def tideline(scores, X):
    cc = Counter(scores)
    #print(cc)
    floating = 0
    for score in range(max(scores)+1):
        floating += cc[score]
        if floating > X:
            break
        X -= floating
    else:
        score += 1
    
    #print(score, X, floating)
    return score + X/floating

# <codecell>

def find_min_vote_proportions(scores):
    X = sum(scores)
    points_limit = tideline(scores, X)
    print(points_limit)
    proportions_needed = []
    for s in scores:
        if s >= points_limit:
            proportions_needed.append(0.0)
        else:
            points_needed = points_limit - s
            #print(s, points_needed, X)
            proportions_needed.append(100*points_needed/X)
    
    return proportions_needed

# <codecell>

# Update this with the filename
fname = "A-large"
with open(fname+".in","r") as fin, open(fname+".out","w") as fout:

    numcases = readline_ints()[0]
    print(numcases, "cases")
    
    for caseno in range(1, numcases+1):
        # Code goes here
        N, *scores = readline_ints()
        result = find_min_vote_proportions(scores)
        
        result_str = " ".join("%f" % p for p in result)
        
        outstr = "Case #%d: %s" % (caseno, result_str)
        fout.write(outstr + "\n")
        print(outstr)

# <codecell>


