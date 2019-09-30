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


ORI_MAP = [
    ['1',  'i',  'j',  'k'],
    ['i', '-1',  'k', '-j'],
    ['j', '-k', '-1',  'i'],
    ['k',  'j', '-i', '-1'],
]

CHAR_MAP = {
    '1':  0, 'i':  1, 'j':  2, 'k':  3,
    '-1': 4, '-i': 5, '-j': 6, '-k': 7,
}

CHAR_ARR = [
    '1', 'i', 'j', 'k', '-1', '-i', '-j', '-k',
]

DIG_MAP = [
    [0, 1, 2, 3, 4, 5, 6, 7],
    [1, 4, 3, 6, 5, 0, 7, 2],
    [2, 7, 4, 1, 6, 3, 0, 5],
    [3, 2, 5, 4, 7, 6, 1, 0],
    [4, 5, 6, 7, 0, 1, 2, 3],
    [5, 0, 7, 2, 1, 4, 3, 6],
    [6, 3, 0, 5, 2, 7, 4, 1],
    [7, 6, 1, 0, 3, 2, 5, 4],
]

# DIG_MAP = None


def decode_pos(pos, L):
    return pos / L, pos % L


def get_i_pos(digits, L, ntotal):
    cur = 0
    for i in xrange(min(4*L, ntotal)):
        cur = DIG_MAP[cur][digits[i % L]]
        if cur == 1:
            return i
    return ntotal


def get_k_pos(digits, L, ntotal):
    cur = 0
    for k in xrange(ntotal-1, max(0, ntotal-4*L), -1):
        cur = DIG_MAP[digits[k % L]][cur]
        if cur == 3:
            return k
    return 0


def calc_slice(digits, L, start, end):
    cur = 0
    for x in xrange(start, end):
        cur = DIG_MAP[cur][digits[x % L]]
    return cur


def solve(L, X, chars):
    ntotal = L * X
    if ntotal < 3:
        return "NO"
    elif ntotal == 3:
        return "YES" if chars == "ijk" else "NO"

    digits = [CHAR_MAP[c] for c in chars]
    i_pos = get_i_pos(digits, L, ntotal)
    k_pos = get_k_pos(digits, L, ntotal)
    if i_pos >= k_pos:
        return "NO"

    start = i_pos + 1
    nstep = k_pos - start
    nstep %= (4 * L)
    if calc_slice(digits, L, start, start+nstep) == 2:
        return "YES"
    else:
        return "NO"


def main(args):
    """ Main entry.
    """
    # global DIG_MAP
    # DIG_MAP = [[-1 for j in range(8)] for i in range(8)]
    # for i in range(8):
    #     for j in range(8):
    #         ri = i / 4
    #         rj = j / 4
    #         vi = i % 4
    #         vj = j % 4
    #         val = CHAR_MAP[ORI_MAP[vi][vj]]
    #         if (ri and not rj) or (rj and not ri):
    #             val = (val + 4) if val < 4 else (val - 4)
    #         DIG_MAP[i][j] = val

    if None == args.outfile:
        outfile = sys.stdout
    else:
        outfile = open(args.outfile, "w")

    with open(args.infile) as infile:
        T = int(infile.readline())
        for i in xrange(1, T + 1):
            [L, X] = [int(x) for x in infile.readline().split()]
            chars = infile.readline().strip()
            outfile.write("Case #%d: %s\n" % (i, solve(L, X, chars)))

    if None != args.outfile:
        outfile.close()

if __name__ == '__main__':
    main(getargs())
