#!/usr/bin/env python

import sys
input = sys.stdin

INF = 2 ** 50

def getBst(step, nod, watched):
    global N, M, bst, cst
    if step == N:
        if watched >= N - M[nod]:
            return 0
        else:
            return INF

    if bst[step][nod][watched] != -1:
        return bst[step][nod][watched]

    bst[step][nod][watched] = (
        getBst(step + 1, 2 * nod, watched) +
        getBst(step + 1, 2 * nod + 1, watched)
    )
    bst[step][nod][watched] = min(bst[step][nod][watched],
        getBst(step + 1, 2 * nod, watched + 1) +
        getBst(step + 1, 2 * nod + 1, watched + 1) +
        cst[step][nod]
    )
    return bst[step][nod][watched]

def main():
    T = int(input.readline())
    for t in range(1, T + 1):
        global N, M, bst, cst
        N = int(input.readline())
        M = map(int, input.readline().split())
        cst = [[] for i in range(N)]
        bst = [[] for i in range(N)]
        for step in range(N - 1, -1, -1):
            cst[step] = map(int, input.readline().split())
            bst[step] = []
            for j in range(len(cst[step])):
                bst[step].append([-1 for k in range(N + 1)])

        getBst(0, 0, 0)
        print "Case #%d: %d" % (t, bst[0][0][0])
    return 0

if __name__ == "__main__":
    main()

