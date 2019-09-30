#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p4.out", "w")

T = int(fin.readline())
for tt in xrange(T):
    K, C, S = map(int, fin.readline().split())
    ans = 0
    if C * S < K:
        ans = "IMPOSSIBLE"
    else:
        cur = 0
        ans = [0 for x in xrange(S)]
        for i in xrange(S):
            if cur == K - 1 and K > 1 and ans[i-1] % K == K - 1:
                S = i
                break
            for j in xrange(C):
                ans[i] *= K
                ans[i] += cur
                if cur < K - 1:
                    cur += 1
        ans = ans[:S]
        ans = map(lambda x: x + 1, ans)
        ans = ' '.join(map(str, ans))

    fout.write("Case #" + str(tt+1) + ": " + str(ans) + "\n")
