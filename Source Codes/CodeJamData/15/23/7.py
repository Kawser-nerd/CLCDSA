from fractions import Fraction
import math

with open("C-small-1-attempt0.in") as infile:
    with open("C.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            nlines = int(next(infile))
            hikers = []

            for L in range(nlines):
                D, H, M = map(int, next(infile).split())

                for i in range(H):
                    hikers.append((D, M+i))

            hikers.sort()

            # Follow first hiker
            time1 = (Fraction(hikers[0][1]) * (360 - hikers[0][0])) / 360
            laps2 = time1 * 1 / Fraction(hikers[1][1]) + Fraction(hikers[1][0])/360

            # Follow second hiker
            time2 = (Fraction(hikers[1][1]) * (360 - hikers[1][0])) / 360
            laps1 = time2 * 1 / Fraction(hikers[0][1]) + Fraction(hikers[0][0])/360

            if laps2 <= 1:
                sol1 = 1
            else:
                sol1 = int(laps2 - 1)

            if laps1 <= 1:
                sol2 = 1
            else:
                sol2 = int(laps1 - 1)

            print("Case #{}: {}".format(case, min(sol1, sol2)), file=outfile)

                

            
            
