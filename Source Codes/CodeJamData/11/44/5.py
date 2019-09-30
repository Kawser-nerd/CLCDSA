from math import *



with open('input.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        primes = sieve(1000000)
        for casenum in range(1, numcases+1):
        #for casenum in range(1, 5):
            print(casenum)
            line = fin.readline().split()
            numplanets = int(line[0])
            numwormholes = int(line[1])
            wormholes = [[] for i in range(numplanets)]
            costs = [10000 for i in range(numplanets)]
            pathsin = [[] for i in range(numplanets)]
            line = fin.readline().split()
            for i in line:
                ints = [int(j) for j in i.split(',')]
                wormholes[ints[0]].append(ints[1])
                wormholes[ints[1]].append(ints[0])

            evalnodes = [0]
            costs[0] = 0

            while (len(evalnodes) > 0):
                source = evalnodes.pop()
                for i in wormholes[source]:
                    if (costs[i] > costs[source] + 1):
                        costs[i] = costs[source] + 1
                        pathsin[i] = [source]
                        if (i not in evalnodes):
                            evalnodes.append(i)
                    elif (costs[i] == costs[source]+1):
                        pathsin[i].append(source)
            threatened = [[] for i in range(numplanets)]
            evalnodes = [0]
            threatened[0] = [set(wormholes[0])]
            while (len(evalnodes) > 0):
                source = evalnodes.pop()
                for i in wormholes[source]:
                    if source in pathsin[i]:
                        for j in threatened[source]:
                            newthreat = j.union(wormholes[i])
                            for k in threatened[i]:
                                if (k >= newthreat):
                                    break
                            else:
                                for k in range(len(threatened[i])):
                                    if threatened[i][k] < newthreat:
                                        threatened[i][k] = newthreat
                                        break
                                else:
                                    threatened[i].append(newthreat)
                                if (i not in evalnodes):
                                    evalnodes.append(i)

            maxthreatnum = 0
            for i in pathsin[1]:
                for j in threatened[i]:
                    if len(j) > maxthreatnum:
                        maxthreatnum = len(j)

            if (costs[1] > 1):
                maxthreatnum -= 1
            maxthreatnum -= costs[1]-1

            solnstr = str(costs[1]-1) + " " + str(maxthreatnum)

            

            













            fout.write("Case #"+str(casenum)+": "+solnstr+'\n')
