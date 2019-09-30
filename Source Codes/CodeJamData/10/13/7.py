#!/usr/local/bin/python3.0

import sys
import math

phi = 0.5 * (1.0 + math.sqrt(5.0))

def countWinners(minA, maxA, minB, maxB):
    result = 0
    numberOfBs = maxB - minB + 1
    for A in range(minA, maxA+1):
        minLosingB = math.ceil (A / phi)
        maxLosingB = math.floor(A * phi)
        loosers = min(maxB, maxLosingB) - max(minB, minLosingB) + 1
        if loosers < 0:
            loosers = 0
        result += numberOfBs - loosers
    return result

def invalidInput():
    sys.exit('Invalid input')

firstLine = next(sys.stdin)

numbers = [ int(s) for s in firstLine.split() ]
if len(numbers) != 1:
    invalidInput()

T = numbers[0]

for caseNumber in range(1, T+1):
    thisLine = next(sys.stdin)

    numbers = [ int(s) for s in thisLine.split() ]
    if len(numbers) != 4:
        invalidInput()
    (minA, maxA, minB, maxB) = tuple(numbers)
    assert(1 <= minA <= maxA <= 10**6)
    assert(1 <= minB <= maxB <= 10**6)
    
    result = countWinners(minA, maxA, minB, maxB)
    print('Case #{0}: {1}'.format(caseNumber, result))