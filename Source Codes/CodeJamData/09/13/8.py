#!/usr/bin/python
import os, sys
import operator

def choose(n, c):
    if c == 0 or c == n:
        return 1
    return reduce(operator.mul, range(n,n-c,-1))/reduce(operator.mul, range(1,c+1))


def buildCardsTable(cards, numNeeded, numPerPack):
    # Start from the bottom.
    # table[x] = expected number of packs needed to get x particular unique cards
    table = []
    possiblePacks = 1.0 * choose(cards, numPerPack)
    for entry in range(0, numNeeded+1):
        if entry == 0:
            # To get 0 cards takes 0 packs (stupid base case)
            table.append(0)
        else:
            # So, we're getting numPerPack cards per pack

            # Form equation x = a*x + b
            a = 0
            b = 0
            #TODOfracs = []
            for numInThisPack in range(numPerPack+1):
                # numInThisPack is the number we got right in this pack.
                # This has a prob of happening of
                # numerator = C(entry, numInThisPack) * C(cards - entry, numPerPack - numInThisPack) / (C(numPerPack, numInThisPack))  (last term for ordering)
                # denominator = C(cards, numPerPack)
                if (numInThisPack <= entry):
                    frac = (choose(entry, numInThisPack) * choose(cards - entry, numPerPack - numInThisPack))
                    #/ (1.0 * choose(numPerPack, numInThisPack))
                    # We used to divide here, but we don't need to since we're dividing a and b by the same amount
                    #frac /= possiblePacks
                    #print "%d %d %f" % (entry, numInThisPack, frac)
                    # frac is the probability we're in this scenario
                    # table[entry - numInThisPack] is how many more turns
                    # we'll need (on average)
                    if (numInThisPack != 0):
                        #print table
                        b += frac * (1 + table[entry - numInThisPack])
                    else:
                        # no luck this time, so we're adding a term of
                        # frac * (1 + x), so each a and b get frac
                        a += frac
                        b += frac
                    #TODOfracs.append(frac)
            #if sum(TODOfracs) < .9999:
            #    print "got bad fracs for entry %d: %s" % (entry, TODOfracs)
            #print "%d %f %f" % (entry, a, b)
            # So x = b/(1-a)
            # (using possiblePacks since we didn't divide by it above)
            table.append(b/(possiblePacks-a))
    #print table
    return table[numNeeded]


def main(filename):
    fileLines = open(filename, 'r').readlines()
    #print len(fileLines)
    index = 0
    words = []
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        [cards, numPerPack] = [int(x) for x in fileLines[index][:-1].split(' ')]
        # In the first pack we automatically get numPerPack unique ones.
        # So, what we really want is 
        numNeeded = cards - numPerPack
        expected = buildCardsTable(cards, numNeeded, numPerPack)

        index += 1
        print "Case #%d: %.9f" % (caseNum+1, 1.0 + expected)


if __name__ == '__main__':
    main(sys.argv[1])
