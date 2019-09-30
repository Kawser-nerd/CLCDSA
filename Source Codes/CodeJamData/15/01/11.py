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


def solve(Smax, Scnt):
    ret = 0
    acc = Scnt[0]
    for i in range(1, len(Scnt)):
        rest = i - acc
        if rest > 0:
            ret += rest
            acc += rest
        acc += Scnt[i]
    return ret


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
            [Smax, Scnt] = infile.readline().split()
            Smax = int(Smax)
            Scnt = [int(cnt) for cnt in list(Scnt)]
            outfile.write("Case #%d: %d\n" % (i, solve(Smax, Scnt)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
