#inputFileName = "test.in"
#inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"

vowels = 'aeiou'

def calcSingleTest(f):
    line = f.readline()
    name = line.split()[0]
    n = int(line.split()[1])
    l = len(name)
    if(l < n):
        return 0
    curCons = 0
    sum = 0
    startPoints = 0
    for pos in range(l):
        ch = name[pos]
        if ch in vowels:
            curCons = 0
        else:
            curCons += 1

        if curCons >= n:
            #startPoints += 1
            startPoints = pos - n + 2
            sum += pos - n + 2
        else:
            sum += startPoints
    return sum


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))

