#!/usr/bin/env python

import sys
input = sys.stdin

def main():
    T = int(input.readline())
    for test in range(1, T + 1):
        N, M = map(int, input.readline().split())
        C = []
        for i in range(N):
            C.append(input.readline().strip())

        ok = True
        for i in range(N):
            for j in range(M):
                if C[i][j] == '#':
                    if i + 1 >= N or j + 1 >= M or C[i + 1][j] != '#' or \
                            C[i][j + 1] != '#' or C[i + 1][j + 1] != '#':
                        ok = False
                        break

                    C[i    ] = C[i    ][:j] + "/\\" + C[i    ][j + 2:]
                    C[i + 1] = C[i + 1][:j] + "\\/" + C[i + 1][j + 2:]

            if not ok:
                break

        print "Case #%d:" % test
        if not ok:
            print "Impossible"
        else:
            print "\n".join(C)

if __name__ == '__main__':
    main()
