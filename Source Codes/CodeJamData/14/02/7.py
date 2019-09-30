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
        case["C"], case["F"], case["X"]  = map(float, fh.readline().strip().split(" "))
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases



def process_case(case):
    cps = [2.0]
    C, F, X = case["C"], case["F"], case["X"] 
    factories2timecomplete = [X/cps[0]]
    elapsed2factory = [0.0]
    factory_count = 0
    while True:
        # make a factory
        elapsed2factory += [elapsed2factory[-1]+C/cps[-1]]
        factory_count += 1
        cps += [cps[-1]+F]
        # determine time for X cookies
        factories2timecomplete += [elapsed2factory[-1]+ X/cps[-1]]
        #print factories2timecomplete
        if factories2timecomplete[-1] > factories2timecomplete[-2]:
            break
    return factories2timecomplete[-2]


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
