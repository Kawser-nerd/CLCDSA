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
        case["N"] = int(fh.readline().strip())
        case["Ns"]  = map(float, fh.readline().strip().split(" "))
        case["Ks"]  = map(float, fh.readline().strip().split(" "))
        cases += [case]
    if fh.readline().strip() !="":
        raise Exception
    return cases


def war(ns, ks):
    s = 0
    '''
    if not ns:
        return 0
    if ns[-1] > ks[-1]:
        #print "Y"
        return 1 + war( ns[:-1], ks[1:] )
    else:
        return 0 + war( ns[:-1], ks[:-1] )
        '''
    while ns:
        if ns[-1] > ks[-1]:
        #print "Y"
            s +=1
            ns =  ns[:-1]
            ks = ks[1:] 
        else:
            ns = ns[:-1]
            ks = ks[:-1]
    return s

def dwar(ns, ks):
    '''
    if not ns:
        return 0
    if ks[-1] > ns[-1]:
        return 0 + dwar( ns[1:], ks[:-1] )
    else:
        return 1 + dwar( ns[:-1], ks[:-1] )
    '''
    s = 0
    while ns:
        if ks[-1] > ns[-1]:
            ns = ns[1:]
            ks = ks[:-1] 
        else:
            s+=1
            ns =  ns[:-1]
            ks = ks[:-1] 
    return s
        

def process_case(case):
    #print case
    ns = sorted(case["Ns"])
    ks = sorted(case["Ks"])
    #print ns, ks
    score_war = war(ns[:], ks[:])
    score_dwar = dwar(ns[:], ks[:])
    return str(score_dwar) + " " + str(score_war)


if __name__ == "__main__":
    cases = read_cases()
    #print cases

    for i, case in enumerate(cases[:]):
        #print i, case
        result = process_case(case)
        print "Case #%s:" % (i+1, ) , result
        #sys.stderr.write("Progress: %d/%d (%d%%) \r" % (i+1, len(cases), int(100.*(i+1)/len(cases) ) ) )
        #sys.stderr.flush()
