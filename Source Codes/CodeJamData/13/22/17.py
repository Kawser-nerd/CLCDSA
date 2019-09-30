def getLine(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        yield line
    inputFile.close()

inputFilename = 'B-large.in'
outputFilename = 'B-large.txt'

tokenIterator = getLine(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING

choose = []
for i in range(3000):
    chs = []
    for j in range(i+1):
        if j==0 or j==i:
            chs.append(1)
        else:
            chs.append(choose[i-1][j-1] + choose[i-1][j])
    choose.append(chs)

# REALLY END PRE-PROCESSING

caseNum = getint()
for case in range(caseNum):

    tmp = get().split()
    n = int(tmp[0])
    x = abs(int(tmp[1]))
    y = int(tmp[2])
    
    lay = 0
    cnt = 0
    for i in xrange(800):
        if cnt + 4*i + 1 <= n:
            cnt += 4*i + 1
            lay += 1
            
    if (x+y)%2 != 0:
        ans = 0.0
    elif (x+y)/2 < lay:
        ans = 1.0
    elif (x+y)/2 > lay or x == 0 or n-cnt == 0:
        ans = 0.0
    else:
        y += 1
        m = n-cnt
        if m - lay*2 >= y:
            ans = 1.0
        else:
            bit = 0
            for i in xrange(y, m+1):
                bit += choose[m][i]
            base = 2**m
            while bit > 1000000000000000000000l:
                bit /= 1000000000000000000000l
                base /= 1000000000000000000000l
            ans = float(bit)/(base)
    
    output = "Case #"+str(case+1)+": "+str(ans)
    outputFile.write(output+"\n")

# BEGIN POST-PROCESSING
outputFile.close()

