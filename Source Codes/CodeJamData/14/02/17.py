inputFile = open('B-large.in', 'r')
lines = inputFile.readlines()
inputFile.close()

outputFile = open('B-large.out', 'w')

numTests = int(lines[0])


def solveCookies(c, f, x):
    accumTime = 0
    farmRate = 0
    while True:
        # two options: Buy, or don't buy
        timeToWait = x/(2.0+farmRate)
        timeIfBuyFarm = (c/(2.0+farmRate) +   # Time to get a farm
                         x/(2.0+farmRate+f))
        if timeToWait <= timeIfBuyFarm:
            return accumTime+timeToWait
        else:
            accumTime += c/(2.0+farmRate)
            farmRate += f

for i in range(1, numTests+1):
    [c, f, x] = map(lambda x: float(x), lines[i].split())

    outputFile.write('Case #'+str(i)+': ' + str(solveCookies(c, f, x))+'\n')
outputFile.close()
    
