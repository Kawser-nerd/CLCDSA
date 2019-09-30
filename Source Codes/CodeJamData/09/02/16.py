#!/usr/bin/python

from sys import stdin, stdout
from collections import defaultdict

def read_ints(strLine):
    return map(int,
               strLine.rstrip('\r\n').split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')

def printfield(field, h, w):
    for row in range(0, h):
        for col in range(0, w):
            print field[row, col],
        print

def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        [H, W] = read_ints(rsreadline())
        field = defaultdict(lambda: 100000)
        for row in range(0, H):
            for col, cell in enumerate(read_ints(rsreadline())):
                field[row, col] = cell

        arrows = {}
        for row in range(0, H):
            for col in range(0, W):
                val, arrows[row, col] = min([(field[row-1, col], 1),
                                             (field[row, col-1], 2),
                                             (field[row, col+1], 3),
                                             (field[row+1, col], 4)])
                if val >= field[row, col]:
                    arrows[row, col] = 0

        result = defaultdict(lambda: ' ')
        nextBasin = 'a'
        for row in range(0, H):
            for col in range(0, W):
                path = [(row, col)]
                while result[path[-1]] == ' ' and arrows[path[-1]] != 0:
                    crow, ccol = path[-1]
                    if arrows[crow, ccol] == 1:
                        crow -= 1
                    if arrows[crow, ccol] == 2:
                        ccol -= 1
                    if arrows[crow, ccol] == 3:
                        ccol += 1
                    if arrows[crow, ccol] == 4:
                        crow += 1
                    path.append((crow, ccol))
                if (result[path[-1]] == ' '):
                    tmpBasin = nextBasin
                    nextBasin = chr(ord(nextBasin)+1)
                    result[path[-1]] = tmpBasin
                else:
                    tmpBasin = result[path[-1]]
                path.pop()
                while path:
                    result[path.pop()] = tmpBasin

        print 'Case #%d:' % (iCase+1)
        printfield(result, H, W)
        stdout.flush()

main()
