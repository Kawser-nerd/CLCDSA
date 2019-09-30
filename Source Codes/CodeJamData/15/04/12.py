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


def solve_3(X, R, C):
    if R == 1:
        return "RICHARD"
    return "GABRIEL"


def solve_4(X, R, C):
    if R == 1:
        return "RICHARD"
    elif R == 2:
        return "RICHARD"
    return "GABRIEL"


def solve_5(X, R, C):
    if R <= 2:
        return "RICHARD"
    elif R == 3 and C == 5:
        return "RICHARD"
    return "GABRIEL"


def solve_6(X, R, C):
    if R <= 3:
        return "RICHARD"
    return "GABRIEL"


def solve(X, R, C):
    if R * C % X != 0:
        return "RICHARD"

    # assume R <= C
    R, C = min(R, C), max(R, C)
    if X <= 2:
        return "GABRIEL"
    elif X == 3:
        return solve_3(X, R, C)
    elif X == 4:
        return solve_4(X, R, C)
    elif X == 5:
        return solve_5(X, R, C)
    elif X == 6:
        return solve_6(X, R, C)
    else:
        return "RICHARD"


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
            [X, R, C] = [int(x) for x in infile.readline().split()]
            outfile.write("Case #%d: %s\n" % (i, solve(X, R, C)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
