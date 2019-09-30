#!/usr/bin/env python

import fileinput
import sys
import math

def read_cases():
    fh = fileinput.input()
    T = int(fh.readline().strip())
    cases = []
    for t in range(T):
        case = {}
        case["R"], case["C"], case["M"]  = map(int, fh.readline().strip().split(" "))
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases


def transp(t):
    return  [[t[i][j] for i in range(len(t))] for j in range(len(t[0]))]

def printable(t, transpose):
    if transpose:
        t = transp(t)
    return "\n" + "\n".join(["".join(map(str, r)) for r in t])

def process_case(case):
    R, C, M = case["R"], case["C"], case["M"] 
    t = R*C     #total
    e = t - M   #empty, with click
    transpose = R>C
    if transpose:
        r, c = C, R
    else:
        r, c = R, C
    base_b = [["." for col in range(c)] for row in range(r)]
    base_b[-1][-1] = "c"
    full_b = [["*" for col in range(c)] for row in range(r)]
    full_b[-1][-1] = "c"
    if M == 0:
        b = base_b
        return printable(b, transpose)
    if e == 1:
        b = [["*" for col in range(c)] for row in range(r)]
        b[-1][-1] = "c"
        return printable(b, transpose)
    if r == 1:
        b = [ ["*"] * M + ["."] * (e-1) + ["c"] ]
        return printable(b, transpose)
    if r == 2:
        if M%2==1: #odd empty
            return "\nImpossible"
        if e==2:   #even empty, special case
            return "\nImpossible"
        else:
            b = base_b
            p = M/2
            for row in range(r):
                for col in range(p):
                    b[row][col] = "*"
            return printable(b, transpose)
    if r == 3:
        if e <= 3 or e == 5 or e== 7:
            return "\nImpossible"
        if e == 4:
            b = full_b
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-2][-1] = "."
            return printable(b, transpose)
        b = base_b
        fcols = M/3
        for row in range(r):
            for col in range(fcols):
                b[row][col] = "*"
        if M%3 == 0:
            return printable(b, transpose)
        if M%3 >= 1:
            b[0][fcols] = "*"
        if M%3 == 2:
            b[0][fcols+1] = "*"
        return printable(b, transpose)
    if r == 4:
        if e <= 3 or e == 5 or e == 7:
            return "\nImpossible"
        if e == 4:
            b = full_b
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-2][-1] = "."
            return printable(b, transpose)
        if e == 6:
            b = full_b
            b[-2][-1] = "."
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-3][-1] = "."
            b[-3][-2] = "."
            return printable(b, transpose)
        if e == 9:
            b = full_b
            b[-2][-1] = "."
            b[-3][-1] = "."
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-3][-2] = "."
            b[-1][-3] = "."
            b[-2][-3] = "."
            b[-3][-3] = "."
            return printable(b, transpose)
        b = base_b
        fcols = M/4
        for row in range(r):
            for col in range(fcols):
                b[row][col] = "*"
        if M%4 == 0:
            return printable(b, transpose)
        if M%4 >= 1:
            b[0][fcols] = "*"
        if M%4 >= 2:
            b[1][fcols] = "*"
        if M%4 == 3:
            b[0][fcols+1] = "*"
        return printable(b, transpose)
    if r >= 5:
        if e <= 3 or e == 5 or e == 7:
            return "\nImpossible"
        if e == 4:
            b = full_b
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-2][-1] = "."
            return printable(b, transpose)
        if e == 6:
            b = full_b
            b[-2][-1] = "."
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-3][-1] = "."
            b[-3][-2] = "."
            return printable(b, transpose)
        if e == 8:
            b = full_b
            b[-2][-1] = "."
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-3][-1] = "."
            b[-3][-2] = "."
            b[-4][-1] = "."
            b[-4][-2] = "."
            return printable(b, transpose)
        if e == 9:
            b = full_b
            b[-2][-1] = "."
            b[-3][-1] = "."
            b[-1][-2] = "."
            b[-2][-2] = "."
            b[-3][-2] = "."
            b[-1][-3] = "."
            b[-2][-3] = "."
            b[-3][-3] = "."
            return printable(b, transpose)
        b = base_b
        fcols = min([M/r, c-3])
        for row in range(r):
            for col in range(fcols):
                b[row][col] = "*"
        M_left = M - (fcols*r)
        #print printable(b, transpose)
        #print b
        
        if fcols:
            tail = process_case( {"R":r, "C":c-fcols, "M":M_left} ).strip().split("\n")
            for row in range(r):
                for col in range(c-fcols):
                    b[row][fcols+col] = tail[row][col]
            return printable(b, transpose)
        
        if M%r == 0 and fcols <= c-2:
            return printable(b, transpose)
        for remainder in range(1,r-1):
            if M%r >= remainder:
                b[remainder-1][fcols] = "*"
        if M%r == r-1:                      # when moving down one pinches
            b[0][fcols+1] = "*"
            #print fcols, c
            if fcols+3 == c:                # when moving right pinches too
                b[0][fcols+2] = "*"         # add another
                b[r-3][fcols] = "."
        #if fcols + 2 == c:
        #    print "oh no", fcols, c
        return printable(b, transpose)

    return "\nworking"


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        #print i, case
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
