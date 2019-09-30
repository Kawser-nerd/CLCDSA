# usage:  (python3 a.py < a.in) > a.out
import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+':', *a, file=sys.stderr, **k)

#---------------------------------------------

'''
n ingreds
p packages per ingred
r ratatouille  (recipe)
q quantities

connect two quantities if they could make rata together
    for n = 2 this is obvs just max-match

obvs sort quantities
    somehow add dynamic programming
    ----
    hm we already know from the FIRST INGREDIENT QUANTITY
        how many servings it will be
    so we just need to hold 50 pointers which we gradually advance!
    tfw greedy solution is best solution

    print()
    print(q)
        print()
            print(j, q[j], bnd_low, bnd_hi, indexes)
                print('add ingred')
                print('overfill')

        print(bnd_low, bnd_hi, indexes)

'''

import math

def run(data):
    n, p, r, q = data
    for qi in q:
        qi.sort()

    indexes = [0] * n

    ret = 0
    for i in range(p):

        servings = q[0][i] / r[0]
        bnd_low = math.ceil(servings/1.1)
        bnd_hi  = math.floor(servings/.9)

        if bnd_low > bnd_hi:
            continue

        # greedily add lowest-valued ingredient at each step, if possible
        # nb: important to update bounds (possible #servings) at each step!
        for j in range(1, n):
            ij = indexes[j]
            if ij >= p:  return ret
            while q[j][ij] < (.9*bnd_low*r[j]):
                ij += 1
                if ij >= p:  return ret
            indexes[j] = ij
            if q[j][ij] <= (1.1*bnd_hi*r[j]):
                lservs = q[j][ij] / r[j]
                bnd_low = max(bnd_low, math.ceil(lservs/1.1))
                bnd_hi  = min(bnd_hi,  math.floor(lservs/.9))
                indexes[j] = ij+1
            else:
                break
        # else = nobreak
        else:
            ret += 1

    return ret

#---------------------------------------------

def read_case():
    n, p = [int(k) for k in list(input().split())]
    r = [int(k) for k in list(input().split())]
    return (n, p, r, [[int(k) for k in list(input().split())] for i in range(n)])

for i in range(int(input())):
    outstr = 'Case #'+str(i+1)+': '+str(run(read_case()))
    print(outstr, ' @ t =', time.clock())
    __builtins__.print(outstr)
