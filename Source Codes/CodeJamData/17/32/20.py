
inputF = open('B-large.in', 'r')
output = open('B-large.out', 'w')

import math

numCases = int(inputF.readline())

import copy

def calculateFloodFill(toFill, notFill):
    toFill = copy.deepcopy(toFill)
    if len(toFill) == 0:
        return 0
    # Extend the ends
    starts = [x[0] for x in toFill] + [x[0] for x in notFill]
    for i in range(len(toFill)):
        newEnd = min([x for x in starts if x >= toFill[i][1]] + [1440])
        toFill = toFill[:i] + [(toFill[i][0], newEnd)] + toFill[i+1:]
    # Extend the starts
    ends = [x[1] for x in toFill] + [x[1] for x in notFill]
    for i in range(len(toFill)):
        newStart = max([x for x in ends if x <= toFill[i][0]] + [0])
        toFill = toFill[:i] + [(newStart, toFill[i][1])] + toFill[i+1:]

    
    if toFill[0][0] == 0 and toFill[-1][1] != 1440:
        toFill += [(notFill[-1][1], 1440)]
    elif toFill[-1][1] == 1440 and toFill[0][0] != 0:
        toFill += [(0, notFill[0][0])]
    lens = [x[1]-x[0] for x in toFill]
    return sum(lens)

def getNumSwaps(c,j):
    ''' Assume sorted '''
    c = copy.deepcopy(c)
    j = copy.deepcopy(j)
    c.reverse()
    j.reverse()
    if not (c and j):
        return 0
    if c[-1][0] < j[-1][0]:
        first = 'c'
        last = 'c'
    else:
        first = 'j'
        last = 'j'
    swaps = 0
    while c!=[] and j!=[]:
        if c[-1][0] < j[-1][0]:
            c.pop()
            if last != 'c':
                swaps += 1
                last = 'c'
        else:
            j.pop()
            if last != 'j':
                swaps += 1
                last = 'j'
    if c and last == 'j':
        swaps += 1
        last = 'c'
    if j and last == 'c':
        swaps += 1
        last = 'j'
    if first == last:
        return swaps
    else:
        return swaps+1
            
def getGaps(gapActs, otherActs):
    ''' Return it sorted with biggest at back '''
    gaps = []
    gapStarts = [x[0] for x in gapActs]
    otherStarts = [x[0] for x in otherActs]
    # Do we need to make a 0-crossing gap?
    if len(otherActs) == 0 or (gapActs[0][0] < otherActs[0][0] and gapActs[-1][0] > otherActs[-1][0]):
        gaps += [gapActs[0][0] + (1440 - gapActs[-1][1])]
    for i in range(len(gapActs)-1):
        # Check if the next act is a gapAct or an otherAct
        nextGapStart = min([x for x in gapStarts if x > gapActs[i][0]] + [1440])
        nextOtherStart = min([x for x in otherStarts if x > gapActs[i][0]] + [1440])
        if nextGapStart < nextOtherStart:
            gaps += [nextGapStart - gapActs[i][1]]
    gaps.sort()
    return gaps
        


def getMinSwaps(cActs, jActs):
    cActs.sort()
    jActs.sort()
    #print cActs, jActs

    # Calculate flood fill times
    cFloodFill = calculateFloodFill(cActs, jActs)
    #print cFloodFill
    jFloodFill = calculateFloodFill(jActs, cActs)
    #print jFloodFill

    numSwaps = getNumSwaps(cActs, jActs)
    #print numSwaps

    if cFloodFill >= 720 and jFloodFill >= 720:
        return numSwaps
    elif cFloodFill < 720:
        gaps = getGaps(jActs, cActs)
        #print gaps
        while cFloodFill < 720:
            cFloodFill += gaps.pop()
            numSwaps += 2
        return numSwaps
    else:
        gaps = getGaps(cActs, jActs)
        #print gaps
        while jFloodFill < 720:
            jFloodFill += gaps.pop()
            numSwaps += 2
        return numSwaps

for i in range(numCases):
    Ac, Aj = inputF.readline().split()
    pancakes = []
    cActs = []
    for j in range(int(Ac)):
        line = inputF.readline().strip().split()
        cActs += [(int(line[0]), int(line[1]))]
    jActs = []
    for j in range(int(Aj)):
        line = inputF.readline().strip().split()
        jActs += [(int(line[0]), int(line[1]))]
    swaps = getMinSwaps(cActs, jActs)
    print i
    output.write('Case #' + str(i+1) + ': ' + str(swaps) + '\n')
inputF.close()
output.close()
