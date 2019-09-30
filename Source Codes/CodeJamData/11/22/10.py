def getToken(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        tokens = line.split()
        for token in tokens:
            if token != '':
                yield token
    inputFile.close()

inputFilename = 'B-large.in'
outputFilename = 'B-large.txt'

tokenIterator = getToken(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING
d = None

class Point:
    def __init__(self, p, v):
        self.p = p
        self.v = v
        self.low  = pp-float((vv-1)*d)/2
        self.high = pp+float((vv-1)*d)/2
        self.time = float((vv-1)*d)/2

caseNum = getint()
for case in range(caseNum):

    c = getint()
    d = getint()
    cList = []
    lowInt = None
    highInt = None
    timeInt = None

    for i in range(c):
        pp = getint()
        vv = getint()
        cList.append((pp,vv))
    cList.sort()
    for i in range(c):
        pp, vv = cList[i]
        u = Point(pp, vv)
        if i == 0:
            lowInt = u.low
            highInt = u.high
            timeInt = u.time
        else:
            if timeInt < u.time:
                timeDiff = u.time-timeInt
                lowInt -= timeDiff
                highInt -= timeDiff
                timeInt = u.time
            need = d - (u.low - highInt)
            timeDiff = timeInt-u.time
            #print timeDiff
            if need > timeDiff:
                lowInt -= float(need-timeDiff)/2
                highInt = u.high + timeDiff + float(need-timeDiff)/2
                timeInt += float(need-timeDiff)/2
            elif need > 0:
                highInt = u.high + need
            else:
                highInt = u.high + max([need,-timeDiff])
        #print "NEW: "+str(u.low)+" "+str(u.high)+" "+str(u.time)
        #print "GET: "+str(lowInt)+" "+str(highInt)+" "+str(timeInt)
        
    output = "Case #"+str(case+1)+": "+str(timeInt)
    outputFile.write(output+"\n")

# BEGIN POST-PROCESSING
outputFile.close()

