#!/usr/local/bin/python3.0

import sys

def printGrid(grid):
    for line in grid:
        print( ''.join( str(int(cell)) for cell in line) )
    print()

def maxLife(rectangles):
    for r in rectangles:
        x1,y1,x2,y2 = r
        assert(1 <= x1 <= x2)
        assert(1 <= y1 <= y2)

    maxX = max( x2 for (x1,y1,x2,y2) in rectangles )
    maxY = max( y2 for (x1,y1,x2,y2) in rectangles )

    grid = [[ False for y in range(maxY+1)] for x in range(maxX+1)]
    for (x1,y1,x2,y2) in rectangles:
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                grid[x][y] = True

    generations = 0
    
    while any( cell for line in grid for cell in line ):
        for x in range(maxX, 0, -1):
            for y in range(maxY, 0, -1):
                top = grid[x][y-1]
                left = grid[x-1][y]
                if top and left:
                    grid[x][y] = True
                elif not top and not left:
                    grid[x][y] = False
        generations += 1

    return generations


def getLineOfNumbers(f):
    return [ int(s) for s in next(f).split() ]

def invalidInput():
    sys.exit('Invalid input')


numbers = getLineOfNumbers(sys.stdin)
if len(numbers) != 1:
    invalidInput()

C = numbers[0]
assert( 1 <= C <= 100 )

for caseNumber in range(1, C+1):
    numbers = getLineOfNumbers(sys.stdin)
    if len(numbers) != 1:
        invalidInput()
    R = numbers[0]
    assert( R >= 1)
    
    rectangles = [ getLineOfNumbers(sys.stdin) for line in range(R) ]
    for line in rectangles:
        if len(line) != 4:
            invalidInput()

    result = maxLife(rectangles)
    print( 'Case #{0}: {1}'.format(caseNumber, result) )
