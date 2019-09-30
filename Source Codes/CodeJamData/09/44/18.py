#!/usr/bin/python

from pprint import pprint
import time
from sys import stdout, stdin, stderr
import sys
from math import sqrt

def read_int(strLine):
    return map(int,
               strLine.split(' '))

def rsreadline():
    return inputfile.readline().rstrip('\r\n')

def solve(rgPlants, fixed):
    r = list(rgPlants)
    del r[fixed]
    return max(rgPlants[fixed][2],
               (sqrt(
               (r[0][0]-r[1][0])**2+
               (r[0][1]-r[1][1])**2) + r[0][2] + r[1][2]) /2)

def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        cPlants = int(rsreadline())
        rgPlants = []
        for i in range(0, cPlants):
            rgPlants.append(read_int(rsreadline()))
        ret = -1.0
        if cPlants == 1:
            ret = rgPlants[0][2]
        if cPlants == 2:
            ret = max(rgPlants[0][2], rgPlants[1][2])
        if cPlants == 3:
            ret = min(
                solve(rgPlants, 0),
                solve(rgPlants, 1),
                solve(rgPlants, 2)
                )
        print 'Case #%d: %.8f' % (iCase + 1, ret)
        stdout.flush()

inputfile = stdin

if __name__ == '__main__' and not sys.argv[0] == '-c':
    main()
elif sys.argv[0] == '-c':
    print time.strftime('%Y%m%d %H%M%S') + ' loaded'
    print '--'
    inputfile = file('input')
    main()
    print '--'
