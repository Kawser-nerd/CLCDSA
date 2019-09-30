# C.py
# Google Code Jam Round 1B 2012 C:
# Benjamin Johnson
# May 6 2012 LIVE
# Lessons Learned: 

import sys,math,time,itertools

filename = "C"

#inputFilename = filename+"-test.in"
#inputFilename = filename+"-small.in"
inputFilename = filename+"-large.in"

outputFilename = filename+".txt"

inputFile = open(inputFilename,"r") #Update these for the problem
outputFile = open(outputFilename,"w") #

startTime = time.time()

testcases = int(inputFile.readline())
for testcase in range(testcases):
    outputStringHeader = "Case #"+str(testcase+1)+":\n"
    outputFile.write(outputStringHeader)
    print "Case #",str(testcase+1)+": "

    # Solve problem... (just the small)
    inputList = map(int,inputFile.readline().split())
    inputList = inputList[1:] # get rid of first number

    # make a dictionary where the sum is the key, and the values are the subsets that make the key
    sums = {}
    solutionKey = None
    for i in range(1,151):
        subsets = list(itertools.combinations(inputList,i))
        for subset in subsets:
            sumOfSet = sum(subset)
            if sumOfSet in sums:
                sums[sumOfSet].append(subset)
                solutionKey = sumOfSet
                break #because we found one already
            else:
                sums[sumOfSet] = [subset]
        if solutionKey:
            break
    if solutionKey:
        for subset in sums[solutionKey]:
            for value in subset:
                outputFile.write("%d "%value)
            outputFile.write("\n")
    else:
        outputFile.write("Impossible\n")
            

    # Output a new line for the next problem
    ##outputFile.write("\n")

outputFile.close()
inputFile.close()

print time.time()-startTime
