# Solution for Google Code Jam 2011 Round 1A Problem A
# Copyright (c) Dan Bjorge, 2011
# All rights reserved

def gcd(n, d):
        while d != 0:
            t = d
            d = n%d
            n = t
        return n

def reducefract(n, d):
    '''Reduces fractions. n is the numerator and d the denominator.'''
    assert d!=0, "integer division by zero"
    assert isinstance(d, int), "must be int"
    assert isinstance(n, int), "must be int"
    greatest=gcd(n,d)
    n/=greatest
    d/=greatest
    return n, d

def solve_case(infile):
    N, Pd, Pg = map(int, infile.readline().split(' '))

    reducedPd = reducefract(Pd, 100)
    reducedPg = reducefract(Pg, 100)
    
    if N < reducedPd[1]:
        print "Broken"
        return

    if Pd > 0 and Pg == 0:
        print "Broken"
        return

    if Pd < 100 and Pg == 100:
        print "Broken"
        return

    print "Possible"

import argparse, os, sys
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input_file')
    parser.add_argument('-o', '--output_file', default=None)
    args = parser.parse_args()
    if args.output_file is None:
        args.output_file = os.path.splitext(args.input_file)[0] + '.out'
    
    with open(args.output_file, 'w', 0) as outfile:
        with open(args.input_file, 'r') as infile:
            num_cases = int(infile.readline().rstrip())
            sys.stdout = outfile
            for case in range(num_cases):
                print "Case #{!s}:".format(case+1),
                solve_case(infile)
            sys.stdout = sys.__stdout__
        
