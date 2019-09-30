#!/usr/bin/env python
# coding: utf-8

#########################################################################
#########################################################################

"""
   File Name: gcj.py
      Author: Wan Ji
      E-mail: wanji@live.com
  Created on: Sat Apr 12 14:59:24 2014 CST
"""
DESCRIPTION = """
"""

import os
import sys
import argparse


def perr(msg):
    """ Print error message.
    """

    sys.stderr.write("%s" % msg)
    sys.stderr.flush()


def pinfo(msg):
    """ Print information message.
    """

    sys.stdout.write("%s" % msg)
    sys.stdout.flush()


def runcmd(cmd):
    """ Run command.
    """

    perr("%s\n" % cmd)
    os.system(cmd)


def getargs():
    """ Parse program arguments.
    """

    parser = argparse.ArgumentParser(description=DESCRIPTION,
                                     formatter_class=
                                     argparse.RawTextHelpFormatter)
    parser.add_argument('infile', type=str, help='input file')
    parser.add_argument('outfile', type=str, nargs='?', default=None,
                        help='output file')

    return parser.parse_args()


def steps_to_get_Pmax_eq_p(P, Pmax):
    nstep = 0
    for p in P:
        nstep += ((p - 1) / Pmax)
    return nstep


def solve(D, P):
    """
    Times of moving: N = argmin_N max(P_N)
    Time costs: N + max(P_N)
    """
    min_costs = max(P)
    for Pmax in range(1, max(P)+1):
        N = steps_to_get_Pmax_eq_p(P, Pmax)
        costs = N + Pmax
        if costs < min_costs:
            min_costs = costs
    return min_costs


def main(args):
    """ Main entry.
    """

    if None == args.outfile:
        outfile = sys.stdout
    else:
        outfile = open(args.outfile, "w")

    with open(args.infile) as infile:
        T = int(infile.readline())
        for i in range(1, T + 1):
            D = int(infile.readline())
            P = [int(p) for p in infile.readline().split()]
            outfile.write("Case #%d: %d\n" % (i, solve(D, P)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
