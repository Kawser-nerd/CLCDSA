import sys

def getnext(gen, type):
    try:
        l = gen.next().strip("\n")
        return type(l)
    except StopIteration:
        return None

def getSpeeds(n, A, X, Y, Z):
    signs = []
    m = len(A)
    for i in range(n):
      signs.append(A[i % m])
      A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    return signs

if __name__ == "__main__":
    infile = open(sys.argv[1],'r')
    reader = infile.xreadlines()
    outfile = open(sys.argv[1]+'-output', 'w')
    nCases = getnext(reader, int)
    for case in range(nCases):
        line = [int(i) for i in getnext(reader, str).split(" ")]
        numSigns = line[0]
        arraySize = line[1]
        X = line[2]
        Y = line[3]
        Z = line[4]
        A = []
        for l in range(arraySize):
            A.append(getnext(reader, int))
        speeds = getSpeeds(numSigns, A, X, Y, Z)
        # Go through the list in reverse
        speeds.reverse()
        sinc = [0]*len(speeds)
        sinc[0] = 1
        for s in range(1, len(speeds)):
            sinc[s] = 1 + sum(sinc[j] for j in range(s) if speeds[j] > speeds[s])
        #print speeds
        outfile.write("Case #%d: %d\n" % (case+1, sum(sinc)%1000000007))




