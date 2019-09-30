#!/usr/local/bin/python3.0

import sys

def printLine(line):
    print( ''.join( el if el is not None else '.' for el in line) )

def shiftToRight(row):
    N = len(row)
    row = [ el for el in row if el is not None ]
    row = [ None for column in range(N-len(row)) ] + row
    return row

def winnersInLine(K, line):
    winners = []
    
    soFar = 0
    color = None
    for el in line:
        if el is None:
            soFar = 0
            color = None
        else:
            if el == color:
                soFar += 1
            else:
                soFar = 1
                color = el
            if soFar == K:
                winners.append(color)
    
    return winners

# returns (red,blue)
def winsLine(K, line):
    result = winnersInLine(K, line)
    return ( 'R' in result, 'B' in result )

    
def winnerAfterRotation(N, K, grid):
    assert(len(grid) == N)
    assert(all( len(row) == N for row in grid ))
    
    grid = [ shiftToRight(row) for row in grid ]
    assert(len(grid) == N)
    assert(all( len(row) == N for row in grid ))

    redWins = blueWins = False
    
    for dir in range(2):
        for r in range(N):
            line = grid[r]
            #printLine(line)
            (redWinsLine, blueWinsLine) = winsLine(K, line)
            redWins |= redWinsLine
            blueWins |= blueWinsLine
        #print()
        for d in range(N):
            l = N - d
            line = [ grid[i][i+d] for i in range(l) ]
            #printLine(line)
            (redWinsLine, blueWinsLine) = winsLine(K, line)
            redWins |= redWinsLine
            blueWins |= blueWinsLine
        #print()
        for d in range(1,N):
            l = N - d
            line = [ grid[i+d][i] for i in range(l) ]
            #printLine(line)
            (redWinsLine, blueWinsLine) = winsLine(K, line)
            redWins |= redWinsLine
            blueWins |= blueWinsLine
        #print()

        grid = [[ grid[(N-1)-c][r] for c in range(N) ] for r in range(N) ]
    
    if redWins:
        if blueWins:
            return 'Both'
        else:
            return 'Red'
    else:
        if blueWins:
            return 'Blue'
        else:
            return 'Neither'


def invalidInput():
    sys.exit('Invalid input')

firstLine = next(sys.stdin)

numbers = [ int(s) for s in firstLine.split() ]
if len(numbers) != 1:
    invalidInput()

T = numbers[0]
assert(T >= 1)

for caseNumber in range(1, T+1):
    thisLine = next(sys.stdin)

    numbers = [ int(s) for s in thisLine.split() ]
    if len(numbers) != 2:
        invalidInput()
    N,K = tuple(numbers)
    assert(3 <= K <= N)
    
    grid = []
    for row in range(N):
        line = next(sys.stdin)
        line = line.strip()
        assert(len(line) == N)
        assert(all( ch in 'RB.' for ch in line ))
        line = [ ch if ch != '.' else None for ch in line ]
        grid.append(line)
    
    result = winnerAfterRotation(N, K, grid)
    print("Case #{0}: {1}".format(caseNumber, result))
    