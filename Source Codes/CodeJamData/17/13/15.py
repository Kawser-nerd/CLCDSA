# usage:  (python3 a.py < a.in) > a.out
import time, sys, inspect

lineno = lambda: inspect.currentframe().f_back.f_back.f_lineno
print = lambda *a, **k: __builtins__.print(str(lineno())+':', *a, file=sys.stderr, **k)

#---------------------------------------------

'''
obvs
    - all debuffs before buffs
    - all buffs before attacks
    - healing might be necessary during buffing phase

so just do brute force of
    (D, B) tuples?
        ie search  [0,100] x [0,100]  space
    then simulate that with healings if necessary
        else attack

'''

def moves_plan(hd, ad, hk, ak, b, d, num_b, num_d):

    ihd = hd

    for i in range(200):
        if hk <= ad:
            # kill
            return i+1

        # heal
        elif hd - ak <= 0 and num_d == 0:
            hd = ihd
        elif hd - (ak-d) <= 0:
            hd = ihd

        # do normal
        elif num_d > 0:
            num_d -= 1
            ak -= d
        elif num_b > 0:
            num_b -= 1
            ad += b

        else:
            hk -= ad

        hd -= ak

    return float('inf')

def run(data):
    hd, ad, hk, ak, b, d = data
    print(data)

    r = min(moves_plan(hd, ad, hk, ak, b, d, num_b, num_d)
        for num_b in range(0,80) for num_d in range(0,80-num_b))

    if r == float('inf'):
        return 'IMPOSSIBLE'

    return r

#---------------------------------------------

def read_case():
    return [int(k) for k in list(input().split())]

for i in range(int(input())):
    outstr = 'Case #'+str(i+1)+': '+str(run(read_case()))
    print(outstr, ' @ t =', time.clock())
    __builtins__.print(outstr)
