# B.py
# Google Code Jam Round 1B 2012 B:
# Benjamin Johnson
# May 6 2012 LIVE
# Lessons Learned: 

import sys,math,time

filename = "B"

#inputFilename = filename+"-test.in"
#inputFilename = filename+"-small.in"
inputFilename = filename+"-large.in"

outputFilename = filename+".txt"

inputFile = open(inputFilename,"r") #Update these for the problem
outputFile = open(outputFilename,"w") #

startTime = time.time()

testcases = int(inputFile.readline())
for testcase in range(testcases):
    outputStringHeader = "Case #"+str(testcase+1)+": "
    outputFile.write(outputStringHeader)
    print "Case #",str(testcase+1)+": "

    # Solve problem...
    inputInts = map(int,inputFile.readline().split())
    N = inputInts[0]
    scores = inputInts[1:]
    solutions = [None]*len(scores)
    X = sum(scores)
    avgP = 1.0/float(len(scores))
    avgS = float(X)/float(len(scores))
    ##print X,avgP,avgS,scores
    #prune outliers? outlier if (avgP+(avgS-score)*(1.0/float(X))) < 0
    prunedScores = []
    prunedCount = 0
    for i in range(len(scores)):
        ##print scores[i]
        if (avgP+(avgS-scores[i])*(1.0/float(X))) >= 0:
            ##print "not outlier"
            prunedScores.append(scores[i])
            solutions[i] = 0
        else:
            prunedScores.append(-1)
            prunedCount += 1
    # Recalculate values
    avgP = 1.0/float(len(prunedScores)-prunedCount)
    avgS = float(sum(prunedScores)+prunedCount)/float(len(prunedScores)-prunedCount)
    for i in range(len(prunedScores)):
        if prunedScores[i] != -1:
            solutions[i] = (100*(avgP+(avgS-prunedScores[i])*(1.0/float(X))))
    ##i = 0
    for solution in solutions:
        if solution < 0:
            solution = 0.0
        ##print scores[i]+(X*(solution/100)) # Final score
        ##i+= 1
        #print solution
        outputFile.write("%1.8f "%solution)
    # Output a new line for the next problem
    outputFile.write("\n")

outputFile.close()
inputFile.close()

print time.time()-startTime
