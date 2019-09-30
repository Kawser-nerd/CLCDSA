#!/usr/bin/python3.2

#filename = 'a_test.in'
filename = 'A-large.in'

FILE = open(filename)
T = int(FILE.readline())

def getCol(array, c):
    return [row[c] for row in array]

def contains(array, char):
    for line in array:
        for elem in line:
            if elem == char:
                return True

def winner(array, char):
    dupArray = [0]*len(array)
    for (i,line) in enumerate(array):
        dupArray[i] = [0]*len(array[0])
        for (j,elem) in enumerate(line):
            if array[i][j] == 'T':
                dupArray[i][j] = char
            else:
                dupArray[i][j] = array[i][j]

    if [dupArray[i][i] for i in range(0,4)] == [char]*4:
        return True
    if [dupArray[3-i][i] for i in range(0,4)] == [char]*4:
        return True

    for i in range(0,4):
        if dupArray[i] == [char]*4:
            return True
        if getCol(dupArray, i) == [char]*4:
            return True

def whoWon(array):
    o = winner(array, 'O')
    x = winner(array, 'X')

    if o and x: print('error, double win!')
    if o: return 'O won'
    if x: return 'X won'
    if not (o or x):
        if contains(array, '.'):
            return 'Game has not completed'
        else:
            return 'Draw'


for i in range(1,T+1):
    array = [ FILE.readline()[0:4] for i in range(0,4)]
    FILE.readline()     # blank line
    print('Case #' + str(i) + ': ' + whoWon(array))