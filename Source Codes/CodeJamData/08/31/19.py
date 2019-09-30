import sys

def getnext(gen, type):
    try:
        l = gen.next().strip("\n")
        return type(l)
    except StopIteration:
        return None


if __name__ == "__main__":
    infile = open(sys.argv[1],'r')
    reader = infile.xreadlines()
    outfile = open(sys.argv[1]+'-output', 'w')
    nCases = getnext(reader, int)
    for case in range(nCases):
        line = getnext(reader, str).split(" ")
        numKeys = int(line[0])
        maxOnKey = int(line[1])
        freq = [int(i) for i in getnext(reader,str).split(" ")]
        freq.sort()
        freq.reverse()
        presses = {}
        pos = 0
        for f in range(numKeys):
            presses[f+1] = freq[pos:pos+maxOnKey]
            pos += maxOnKey
        print presses
        u = 0
        for s in presses.keys():
            u += sum(s*k for k in presses[s])
        outfile.write("Case #%d: %d\n" % (case+1, u))






