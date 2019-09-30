inFile = open("B-large.in.in", 'r')
outFile = open("B.out",'w')
N = int(inFile.readline())

for I in range(1,N+1):
    numPoints, minDist = tuple([int(x) for x in inFile.readline().split()])
    vendors = []
    for i in range(numPoints):
        point, numVendors = tuple([int(x) for x in inFile.readline().split()])
        for j in range(numVendors):
            vendors.append(point)
    
    maxMove = 0
    for i in range(1, len(vendors)):
        if vendors[i]-vendors[i-1] < minDist:
            maxMove = max(maxMove, vendors[i-1]-vendors[i]+minDist)
            vendors[i] = vendors[i-1]+minDist
            
    outFile.write("Case #"+str(I)+": "+str(maxMove/2)+"\n")
    print("Case #"+str(I)+": "+str(maxMove/2))
