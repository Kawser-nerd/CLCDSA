""" imports """
#pylint: disable=W0622
#pylint: disable=E0102
from __future__ import division
import glob, pickle, os, time, sys, argparse
from copy import copy
import numpy as np
from pylab import *
from pprint import pprint

""" global variables """

""" classes """

""" functions """
def CountBits(n):
    n = (n & 0x5555555555555555) + ((n & 0xAAAAAAAAAAAAAAAA) >> 1)
    n = (n & 0x3333333333333333) + ((n & 0xCCCCCCCCCCCCCCCC) >> 2)
    n = (n & 0x0F0F0F0F0F0F0F0F) + ((n & 0xF0F0F0F0F0F0F0F0) >> 4)
    n = (n & 0x00FF00FF00FF00FF) + ((n & 0xFF00FF00FF00FF00) >> 8)
    n = (n & 0x0000FFFF0000FFFF) + ((n & 0xFFFF0000FFFF0000) >> 16)
    n = (n & 0x00000000FFFFFFFF) + ((n & 0xFFFFFFFF00000000) >> 32) # This last & isn't strictly necessary.
    return n

class App(object):
    R = None
    C = None
    n = None
    def __init__(self, R, C, n):
        self.R = R
        self.C = C
        self.n = n

    def is_occupied(self, r, c):
        if r < 0 or c < 0:
            return False
        i = r*self.C + c
        return (self.n & (1 << i)) > 0

    def unhappiness(self):
        score = 0
        for r in range(self.R):
            for c in range(self.C):
                if self.is_occupied(r, c):
                    for (dc, dr) in [(-1, 0), (0, -1)]:
                        if self.is_occupied(r+dr, c+dc):
                            score += 1
        return score

def split(xtra, sides):
    assert sides >= 0
    m = min(xtra, sides)
    return m, xtra - m

def divup(a, b):
    return int(np.ceil(a/b))

def solve_uneven(R, C, xtra, corners=True):
    if not corners:
        xtra += 1
    if xtra <= 0:
        return 0

    if corners:
        sides = 2*(R//2 + C//2)
        xtra_sides, xtra_inner = split(xtra, sides)
        return xtra_sides*3 + xtra_inner*4
    else:
        sides = 2*(R//2+1 + C//2+1) - 4
        xtra_corners, xtra_other = split(xtra, 4)
        xtra_sides, xtra_inner = split(xtra_other, sides-4)
        return xtra_corners*2 + xtra_sides*3 + xtra_inner*4

def solve(R, C, N):
    if N < R*C/2:
        return 0
    if R > C:
        (R, C) = (C, R)
    xtra = N - int(np.ceil(R*C/2.))

    if R == 1:
        cnt = 0
        if xtra > 0:
            if C % 2 == 0:
                cnt += 1 + (xtra-1)*2
            else:
                cnt = 2*xtra
        return cnt

    if R*C % 2 != 0:
        return min(solve_uneven(R, C, xtra, corners=True), solve_uneven(R, C, xtra, corners=False))

    else:
        sides = R + C - 2
        xtra_corners, xtra_other = split(xtra, 2)
        xtra_sides, xtra_inner = split(xtra_other, sides-2)
        return xtra_corners*2 + xtra_sides*3 + xtra_inner*4


def main():
    ### parse input ###
    ## parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", default="default.in", nargs='?')
    parser.add_argument("-t", "--test", action="store_true")
    parser.add_argument("-l", "--lazytest", action="store_true")
    args = parser.parse_args()
    output = ""
    TIC = time.time()

    ## read input lines
    input_lines = open(args.filename).readlines()
    def read_line():
        return input_lines.pop(0).strip()
    def read_ints():
        return [int(x) for x in read_line().split(' ')]
    def read_floats():
        return [float(x) for x in read_line().split(' ')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        R, C, N = read_ints()

        ### calculate answer ###
        answer = solve(R, C, N)
        assert answer != None

        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str

    ## write output
    ofile = open('output', 'w').write(output)
    TOC = time.time()
    #print "done in {} s".format(TOC-TIC)


    ### test ###
    if args.test:
        def filter_extension(filename):
            filename_parts = filename.split('.')
            if len(filename_parts) > 1:
                filename_parts = filename_parts[:-1]
            return '.'.join(filename_parts)

        print
        print "== TESTING VALIDITY =="

        try:
            # check if all input was used
            assert not len([l for l in input_lines if l.strip()]), "Not all input was used"

            # filter extension of filename
            filename_without_extension = filter_extension(args.filename)

            # get calculated and correct lines
            calculated_lines = [l.strip() for l in output.split('\n') if l.strip()]
            correct_lines = [l.strip() for l in open("{}.out".format(filename_without_extension)).readlines() if l.strip()]

            # check if number of lines match
            assert len(correct_lines) == len(calculated_lines), "calculated {} lines but expected {}".format(len(calculated_lines), \
                                                                len(correct_lines))

            # apply lazytest: filter away test numer
            unfiltered_calculated_lines = calculated_lines
            unfiltered_correct_lines = correct_lines
            if args.lazytest:
                def filter_test_number(line):
                    if line.startswith("Case #"):
                        parts = line.split('#')
                        parts[1] = parts[1][parts[1].index(':'):]
                        return '#'.join(parts)
                    else:
                        return line
                calculated_lines = [filter_test_number(l) for l in calculated_lines]
                correct_lines = [filter_test_number(l) for l in correct_lines]

            # get lines that don't match
            incorrect_line_numbers = []
            for line_number, (correct_line, calculated_line) in enumerate(zip(correct_lines, calculated_lines)):
                if correct_line != calculated_line:
                    incorrect_line_numbers.append(line_number)
            if len(incorrect_line_numbers):
                error_msg = "\n"
                for line_number in incorrect_line_numbers:
                    error_msg += '    "{}"  should be  "{}"\n'.format(unfiltered_calculated_lines[line_number],
                                                                      unfiltered_correct_lines[line_number])
                raise AssertionError(error_msg)

            print "SUCCESS"

        except AssertionError as ex:
            print "\nFAILED:"
            print str(ex)
        print


if __name__ == '__main__':
    main()
