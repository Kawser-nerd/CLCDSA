#!/usr/bin/env python

f = open("D.in", "rt")

def main():
    T = int(f.readline().strip())
    for test in range(T):
        N = int(f.readline().strip())
        c = [
            [int(a) for a in f.readline().split()]
            for i in range(N)
        ]
        if N == 1:
            print "Case #%d: %.6lf" % (test + 1, c[0][2])
            continue
        if N == 2:
            print "Case #%d: %.6lf" % (test + 1, max(c[0][2], c[1][2]))
            continue

        assert N == 3
        SOL = 1e1000
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                for k in range(N):
                    if i == k or j == k:
                        continue

                    R2 = c[k][2]
                    R1 = (
                        ((c[i][0] - c[j][0]) ** 2 + (c[i][1] - c[j][1]) ** 2) ** 0.5 + 
                        c[i][2] + c[j][2]
                    ) * 0.5
                    R = max(R1, R2)

                    SOL = min(SOL, R)

        print "Case #%d: %.6lf" % (test + 1, SOL)

    return 0

if __name__ == "__main__":
    main()

