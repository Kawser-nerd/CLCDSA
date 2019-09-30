#!/usr/bin/env python

import sys
input = sys.stdin

def main():
    MAXC = 105
    T = int(input.readline())
    for t in range(1, T + 1):
        M = [[0 for j in range(MAXC + 1)] for i in range(MAXC + 1)]

        R = int(input.readline())
        for i in range(R):
            X1, Y1, X2, Y2 = map(int, input.readline().split())
            for x in range(X1, X2 + 1):
                for y in range(Y1, Y2 + 1):
                    M[x][y] = 1

        step = 0
        done = True if R == 0 else False
        while not done:
            done = True
            step += 1
            for x in range(MAXC, -1, -1):
                for y in range(MAXC, -1, -1):
                    if M[x][y] == 0:
                        if x >= 1 and y >= 1 and M[x - 1][y] and M[x][y - 1]:
                            M[x][y] = 1
                            done = False
                    else:
                        if (x == 0 or M[x - 1][y] == 0) and (y == 0 or M[x][y - 1] == 0):
                            M[x][y] = 0
                        else:
                            done = False
                    if (x == MAXC or y == MAXC) and M[x][y]:
                        raise Exception("MAXC too small")

        print "Case #%d: %d" % (t, step)
    return 0

if __name__ == "__main__":
    main()

