inputF = open('B-large.in', 'r')
output = open('B-large.out', 'w')


numCases = int(inputF.readline())

def getNumRides(ticketCustomerPairs, numSeats, numCusts):
    custCounts = {}
    seatCounts = {}
    for i in range(1, numCusts+1):
        custCounts[i] = 0
    for i in range(1, numSeats+1):
        seatCounts[i] = 0
    for (pi, ci) in ticketCustomerPairs:
        custCounts[ci] += 1
        seatCounts[pi] += 1

    lowerBound = max(custCounts.values())
    freeSeats = 0
    for i in range(1, numSeats+1):
        if seatCounts[i] <= lowerBound:
            freeSeats += lowerBound - seatCounts[i]
        else:
            freeSeats -= seatCounts[i] - lowerBound
            while freeSeats < 0:
                lowerBound += 1
                freeSeats += i
    # lowerBound should be right
    upgrades = 0
    for i in range(1, numSeats+1):
        if seatCounts[i] > lowerBound:
            upgrades += seatCounts[i]-lowerBound
    return lowerBound, upgrades
    

for i in range(numCases):
    n, c, m = inputF.readline().split()
    #print n,m,c
    ticketCustomerPairs = []
    for j in range(int(m)):
        (pi, ci) = inputF.readline().split()
        ticketCustomerPairs += [(int(pi), int(ci))]
    numRides, numUpgrades = getNumRides(ticketCustomerPairs, int(n), int(c))
    
    output.write('Case #' + str(i+1) + ': ' + str(numRides) + ' ' + str(numUpgrades) + '\n')
inputF.close()
output.close()
