import math
M = 1000000007
#table[R, top, num12]
#R-len(top)
debug = False

def count12s(n):
    return 3**(max(0, n-1))

def count12s4(n):
    return 2**(max(0, n-1))

def count12(n):
    if n == 0:
        return 1
    if n == 1:
        return 2
    total = 0
    for square2 in xrange(n+1):
        line2 = n - square2
        comb = math.factorial(n) / math.factorial(square2) / math.factorial(line2)
        if debug:
            print "c", square2, line2, comb * 3**(max(0, square2-(line2 == 0))) * 6**(max(0, line2-1))
            print comb, 3**(max(0, square2-(line2 == 0))), 6**(max(0, line2-1))
        total = (total + comb * 3**(max(0, square2-(line2 == 0))) * 6**(max(0, line2-1))) % M
    return total

def num(R, top, num12, table, rowtypes):
    if R - len(top) == 0:
        return int(num12 == (top == "12" or top == "112"))
    elif R - len(top) < 0:
        return 0

    newR = R - len(top)
    total = 0
    if top == "12" or top == "112":
        if num12 - 1 < 0:
            return 0
        return table[(newR, "33", num12 - 1)]
    elif top == "2":
        if newR/4 + 1 < num12:
            return 0
        return table[(newR, "33", num12)]
    elif top == "33":
        if newR/4 + 1 < num12:
            return 0
        #print table.keys(), R, num12
        if "12" in rowtypes:
            return table[(newR, "12", num12)] + table[(newR, "2", num12)]
        else:
            return table[(newR, "112", num12)] + table[(newR, "2", num12)]
    else:
        causeerror

for case in range(input()):
    print "Case #%s:" % (case+1),
    R, C = map(int, raw_input().split())
    double12possible = (C%3 == 0) or (C%4 == 0)
    double12more = (C%6 == 0)
    if debug:
        print R,C
        print double12possible, R%3
    if double12possible:
        rowtypes = ["33", "2"]
        if C%3 == 0:
            rowtypes.append("12")
        if C%4 == 0:
            rowtypes.append("112")
        table = {}
        for r in xrange(R+1):
            for num12 in xrange(r/4 + 2):
                for top in rowtypes:
                    if debug:
                        print "filling", r, top, num12, ":",
                    table[(r, top, num12)] = num(r, top, num12, table, rowtypes)
                    if debug:
                        print table[(r, top, num12)]
        if debug:
            print table
        total = 0
        for num12 in xrange(R/4 + 2):
            if debug:
                print "num12", num12, [table[(R, top, num12)] for top in rowtypes]
            for top in rowtypes:
                if double12more:
                    total = (total + count12(num12) * table[(R, top, num12)]) % M
                elif C%4 == 0:
                    total = (total + count12s4(num12) * table[(R, top, num12)]) % M
                else:
                    total = (total + count12s(num12) * table[(R, top, num12)]) % M
                if debug:
                    print total
        print total
    elif C % 4 == 0:
        rowtypes = ["33", "2", "112"]
        table = {}
        for r in xrange(R+1):
            for num12 in xrange(r/4 + 2):
                for top in rowtypes:
                    if debug:
                        print "filling", r, top, num12, ":",
                    table[(r, top, num12)] = num(r, top, num12, table)
                    if debug:
                        print table[(r, top, num12)]
        if debug:
            print table
        total = 0
        for num12 in xrange(R/4 + 2):
            if debug:
                print "num12", num12, [table[(R, top, num12)] for top in rowtypes]
            for top in rowtypes:
                if double12more:
                    total = (total + count12(num12) * table[(R, top, num12)]) % M
                else:
                    total = (total + count12s(num12) * table[(R, top, num12)]) % M
                if debug:
                    print total
        print total
    else:
        rowtypes = ["33", "2"]
        """
        table = {}
        num12 = 0
        for r in xrange(R+1):
            for top in rowtypes:
                if debug:
                    print "filling", r, top, num12, ":",
                table[(r, top, num12)] = num(r, top, num12, table)
                if debug:
                    print table[(r, top, num12)]
            table[(r, '12', num12)] = 0
        if debug:
            print table
        total = 0
        for top in rowtypes:
            total = (total + 6**(max(0, num12-1)) * table[(R, top, num12)]) % M
        print "guess1", total
        print "guess2",
        """
        if R % 3 == 1:
            print 1
        elif R % 3 == 0:
            print 2
        else:
            print 1
