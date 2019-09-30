# -*- coding: utf-8 -*-
# <nbformat>3</nbformat>

# <codecell>

def readline_ints():
    return [int(num) for num in fin.readline().strip().split()]

# <codecell>

import itertools
def ordered_subsets_sums(S):
    lim = sum(S)//2
    for i in range(1, len(S)):
        for subset in itertools.combinations(S, i):
            sub_sum = sum(subset)
            if sub_sum > lim:
                break
            yield subset, sub_sum
        

# <codecell>

def find_collision(S):
    sums = {}
    for sub, sub_sum in ordered_subsets_sums(S):
        if sub_sum in sums:
            return sums[sub_sum], sub
        sums[sub_sum] = sub

# <codecell>

# Update this with the filename
fname = "C-large"
with open(fname+".in","r") as fin, open(fname+".out","w") as fout:

    numcases = readline_ints()[0]
    print(numcases, "cases")
    
    for caseno in range(1, numcases+1):
        # Code goes here
        N, *S = readline_ints()
        S.sort()
        coll = find_collision(S)
        if coll is None:
            result = "Impossible"
        else:
            s1, s2 = coll
            result = " ".join(str(n) for n in sorted(s1)) + "\n" + " ".join(str(n) for n in sorted(s2))
        
        outstr = "Case #%d:\n%s" % (caseno, result)
        fout.write(outstr + "\n")
        print(outstr)

# <codecell>


