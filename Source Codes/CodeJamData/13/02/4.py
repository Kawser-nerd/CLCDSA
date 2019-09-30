#!/usr/bin/python3.2

#filename = 'b_test.in'
#filename = 'B-small-attempt0.in'
filename = 'B-large.in'

def getCol(array,c):
    return [row[c] for row in array]

def mowable(array):
    for i,line in enumerate(array):
        for j,col in enumerate(line):
            if (array[i][j] < max(array[i])) and (array[i][j] < max(getCol(array,j))):
                return 'NO'
    return 'YES'

FILE = open(filename)
T = int(FILE.readline())

for i in range(1, T+1):
    rawLine = FILE.readline().split(' ')
    rows, cols = int(rawLine[0]), int(rawLine[1])

    array = [0]*rows
    for r in range(0,rows):
        array[r] = [int(x) for x in FILE.readline().split(' ')]

    print('Case #' + str(i) + ': ' + mowable(array))