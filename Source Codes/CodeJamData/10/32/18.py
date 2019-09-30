'''
Created on May 23, 2010

@author: Darren
'''

from __future__ import division
from math import log, ceil
if __name__ == "__main__":
    f = open("B-large.in", "r")
    fout = open("B-large.out", "w")
    # T, the number of test cases in the input file
    T = int(f.readline())
    for i in xrange(T):
        L, P, C = [int(x) for x in f.readline().split()]
        result = int(ceil(log(log(P/L, C), 2)))
        if result < 0: result = 0
        fout.write(''.join(('Case #', str(i+1), ': ', str(result), '\n')))
    fout.close()
    f.close()