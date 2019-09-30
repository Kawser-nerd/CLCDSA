def getLine(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        yield line
    inputFile.close()

inputFilename = 'A-large.in'
outputFilename = 'A-large.txt'

tokenIterator = getLine(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING

caseNum = getint()
for case in range(caseNum):

    tmp = get().split()
    a = int(tmp[0])
    n = int(tmp[1])
    
    tmp = get()
    x = [int(tmpi) for tmpi in tmp.split()]
        
    x.sort()
    ans = n
    cnt = 0
    for i in xrange(n):
        if x[i] < a:
            a += x[i]
        elif a == 1:
            break
        else:
            while x[i] >= a:
                a += a-1
                cnt += 1
            a += x[i]
        if ans > cnt + (n-i-1):
            ans = cnt + (n-i-1)
    
    output = "Case #"+str(case+1)+": "+str(ans)
    outputFile.write(output+"\n")

# BEGIN POST-PROCESSING
outputFile.close()

