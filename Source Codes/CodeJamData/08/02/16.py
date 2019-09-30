def hhmm2min(time):
    (hh,mm) = time.split(':')
    hh = int(hh)
    mm = int(mm)
    return hh*60 + mm

def min2hhmm(min):
    hh = int(min / 60)
    mm = min % 60
    return '%02d:%02d' % (hh, mm)

filename = raw_input("Enter input file name: ")
input = file(filename,'r')

filename = raw_input("Enter output file name: ")
output = file(filename,'w')


numCases = eval(input.readline())

#print 'number of cases: ', numCases

for case in range(numCases):

#    print 'case: ',case+1

    turnAround = eval(input.readline())
    (a2bTrips, b2aTrips) = input.readline().split()
    a2bTrips = int(a2bTrips)
    b2aTrips = int(b2aTrips)

#    print 'turn arround, A trips, B trips: ', turnAround, a2bTrips, b2aTrips

    aTrips = []

    for a in range(a2bTrips):
        line = input.readline()
        (depart, arrive) = line.split()
        aTrips.append((hhmm2min(depart),hhmm2min(arrive)+turnAround))

#        print 'A: depart, arrive: ', depart, arrive

    aTrips.sort()
#    print aTrips

    bTrips = []

    for b in range(b2aTrips):
        line = input.readline()
        (depart, arrive) = line.split()
        bTrips.append((hhmm2min(depart),hhmm2min(arrive)+turnAround))

#        print 'B: depart, arrive: ', depart, arrive

    bTrips.sort()
#    print bTrips

    # now, start sending trains as necessary

    aTrainsNeeded = 0
    bTrainsNeeded = 0 

    aAvailable = []
    bAvailable = []

    while aTrips or bTrips:

#        print
#        print 'A: ',aTrips
#        print 'aAvailable: ',aAvailable
#        print 'B: ',bTrips
#        print 'bAvailable: ',bAvailable

        # check on next departure time
        if aTrips and bTrips:
            if min(aTrips) <=  min(bTrips):
#                print 'in A-min portion'
                # see if a train is available for 'A' trip
                a = aTrips.pop(0)
                if (len(aAvailable) > 0 and
                    a[0] >= aAvailable[0]):
                    aAvailable.pop(0)
                else:
                    aTrainsNeeded = aTrainsNeeded + 1
                bAvailable.append(a[1])
                bAvailable.sort()
            else:
#                print 'in B-min portion'
                # see if a train is available for 'B' trip
                b = bTrips.pop(0)
                if (len(bAvailable) > 0 and
                    b[0] >= bAvailable[0]):
                    bAvailable.pop(0)
                else:
                    bTrainsNeeded = bTrainsNeeded + 1
                aAvailable.append(b[1])
                aAvailable.sort()
        elif aTrips:
            # see if a train is available for 'A' trip
            a = aTrips.pop(0)
            if (len(aAvailable) > 0 and
                a[0] >= aAvailable[0]):
                aAvailable.pop(0)
            else:
                aTrainsNeeded = aTrainsNeeded + 1
            bAvailable.append(a[1])
            bAvailable.sort()
        else:
            # see if a train is available for 'B' trip
            b = bTrips.pop(0)
            if (len(bAvailable) > 0 and
                b[0] >= bAvailable[0]):
                bAvailable.pop(0)
            else:
                bTrainsNeeded = bTrainsNeeded + 1
            aAvailable.append(b[1])
            aAvailable.sort()
            

    print 'Case #%s: %s %s' % (case+1, aTrainsNeeded, bTrainsNeeded)
    output.write('Case #%s: %s %s\n' %  (case+1, aTrainsNeeded, bTrainsNeeded))
