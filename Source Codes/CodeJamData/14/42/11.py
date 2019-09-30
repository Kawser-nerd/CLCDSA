def solve(seq):
    cost = 0
    while seq:
        e, i = min((seq[i], i) for i in range(len(seq)))

        sw_left = i
        sw_right = (len(seq)-1) - i

        cost += min(sw_left, sw_right)

        del seq[i]
    return cost

import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            n = int(inf.readline())
            seq = map(int, inf.readline().split())
            outf.write('Case #{}: {}\n'.format(t,solve(seq)))
