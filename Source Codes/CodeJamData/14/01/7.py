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
        case["1"] = {}
        case["1"]["r"] = map(int, fh.readline().strip().split(" "))[0]
        case["1"]["d"] = []
        for i in range(4):
            case["1"]["d"] += [map(int, fh.readline().strip().split(" "))]
        case["2"] = {}
        case["2"]["r"] = map(int, fh.readline().strip().split(" "))[0]
        case["2"]["d"] = []
        for i in range(4):
            case["2"]["d"] += [map(int, fh.readline().strip().split(" "))]
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases



def process_case(case):
    t1 = case["1"]["d"][case["1"]["r"]-1]
    t2 = case["2"]["d"][case["2"]["r"]-1]
    p = set(t1) & set(t2)
    if len(p) == 1:
        return list(p)[0]
    if len(p):
        return "Bad magician!"
    return "Volunteer cheated!"


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
