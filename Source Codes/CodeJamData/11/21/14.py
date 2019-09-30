def getToken(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        tokens = line.split()
        for token in tokens:
            if token != '':
                yield token
    inputFile.close()

inputFilename = 'A-large.in'
outputFilename = 'A-large.txt'

tokenIterator = getToken(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING

caseNum = getint()
for case in range(caseNum):

    n = getint()
    x = []
    wins = {}
    losses = {}
    wp = {}
    owp = {}
    oowp = {}
    for i in range(n):
        s = get()
        x.append(s)
        wins[i] = 0
        losses[i] = 0
        for j in range(n):
            if s[j] == '0':
                losses[i] += 1
            elif s[j] == '1':
                wins[i] += 1
        wp[i] = float(wins[i])/(wins[i]+losses[i])
    for i in range(n):
        count = 0
        sumwp = 0
        s = x[i]
        for j in range(n):
            if s[j] == '0':
                sumwp += float(wins[j]-1)/(wins[j]+losses[j]-1)
                count += 1
            elif s[j] == '1':
                sumwp += float(wins[j])/(wins[j]+losses[j]-1)
                count += 1
        owp[i] = float(sumwp)/count
    for i in range(n):
        count = 0
        sumwp = 0
        s = x[i]
        for j in range(n):
            if s[j] == '0' or s[j] == '1':
                sumwp += owp[j]
                count += 1
        oowp[i] = float(sumwp)/count
        
    output = "Case #"+str(case+1)+":\n"
    for i in range(n):
        output += str(float(0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]))
        output += "\n"
    outputFile.write(output)

# BEGIN POST-PROCESSING
outputFile.close()

