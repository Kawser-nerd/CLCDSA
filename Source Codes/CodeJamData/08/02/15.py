import sys

def toMinutes(str):
    a,b = str.split(':')
    return int(a)*60 + int(b)

fin = open(sys.argv[1])

nCases = int(fin.readline())

# events:
# note ready events are processed before departure events, which may be significant
# 0 - A ready
# 1 - A departs
# 2 - B ready
# 3 - B departs

for j in range(nCases):
    events = []
    turnAround = int(fin.readline())
    NA, NB = [int(x) for x in fin.readline().split()]
    for i in range(NA):
        times = fin.readline().split()
        times = [toMinutes(x) for x in times]
        # A departure events
        events.append( (times[0], 1) )
        events.append( (times[1]+turnAround, 2) )
    
    for i in range(NB):
        times = fin.readline().split()
        times = [toMinutes(x) for x in times]
        events.append( (times[0], 3) )
        events.append( (times[1]+turnAround, 0) )
    
    events.sort()
    aCounter = 0
    bCounter = 0
    minA = 0
    minB = 0
    for e in events:
        #print e[0]/60,':',e[0]%60,"  ",e[1],
        if e[1] == 0:
            aCounter += 1
        elif e[1] == 1:
            aCounter -= 1
        elif e[1] == 2:
            bCounter += 1
        else:
            bCounter -= 1
            
        minA = min(minA, aCounter)
        minB = min(minB, bCounter)
        #print aCounter, bCounter
    print "Case #%d: %d %d" %(j+1, -minA, -minB) 