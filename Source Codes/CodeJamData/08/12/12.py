#!/usr/bin/env python

import sys

argv = sys.argv[1:]

testFile = open(argv[0] + '.in', 'rb')
outFile = open(argv[0] + '.out', 'wb')

nCases = int(testFile.readline())
for i in xrange(1, nCases+1):
    nFlavors = int(testFile.readline())
    nCustomers = int(testFile.readline())
    customersUnmalted = []
    customersMalted = [-1]*nCustomers
    for j in xrange(nCustomers):
        [nLiked, customer] = testFile.readline().split(' ', 1)
        nLiked = int(nLiked)
        
        unmalted = []
        for k in xrange(nLiked):
            [flavor, malted, customer] = (customer.split(' ', 2) + [''])[:3]
            flavor = int(flavor)
            malted = int(malted)
            
            if malted: customersMalted[j] = flavor
            else: unmalted.append(flavor)
        customersUnmalted.append(unmalted)
    
    malted = [0]*nFlavors
    satisfied = [len(unmalted) for unmalted in customersUnmalted]
    while not all(satisfied):
        unsatisfied = satisfied.index(0)
        malt = customersMalted[unsatisfied]
        if malt == -1:
            break
        else:
            idx = unsatisfied
            while True:
                customersMalted.pop(idx)
                customersUnmalted.pop(idx)
                try:
                    idx = customersMalted.index(malt)
                except ValueError:
                    break
            
            for unmalted in customersUnmalted:
                try:
                    unmalted.remove(malt)
                except ValueError:
                    pass
            
            malted[malt - 1] = 1
        
        satisfied = [len(unmalted) for unmalted in customersUnmalted]
    
    outFile.write('Case #%i: ' % i)
    if all(satisfied):
        outFile.write(' '.join(map(str, malted)))
    else:
        outFile.write('IMPOSSIBLE')
    outFile.write('\n')

outFile.close()
testFile.close()
