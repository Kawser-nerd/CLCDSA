import sys
import random

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################


def read_input():
    N, W, L = int_input()
    rs = int_input()
    r = [(rs[i], i) for i in range(len(rs))]
    r.sort(reverse = True)
    return W, L, r

def solve(W, L, r):
    positionned = []
    
    for ri in r:
        ok = False
        while not ok:
            x = 1 + random.randrange(W-1)
            # x =
            y = 1 + random.randrange(L-1)
            ok = True
            for pos in positionned:
                r2, x2, y2 = pos
                if((x2-x)**2 + (y2-y)**2 <= (r2[0] + ri[0])**2):
                    ok = False
                    break

        positionned.append([ri, x, y])

    #Print them in the correct order
    result = [(positionned[i][0][1], positionned[i]) for i in range(len(positionned))]
    result.sort()
    real_result = ""
    for res in result:
        real_result += str(res[1][1]) + " " + str(res[1][2]) + " "

    return real_result

#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

