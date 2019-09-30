# May, 23, 2010
# Round 1C
# "Rope Intranet"

from time import time

#inpath = "A-sample.in"
inpath = "A-large.in"
#inpath = 'A-small-attempt0.in'
outpath = "A.out"

fin = open(inpath)
fout = open(outpath, 'w')

def Intranet(wires):
    count = 0
    for i in range(len(wires)):
        x = wires[i]
        for y in wires[i+1:]:
            t = (x[0] - y[0])*(x[1] - y[1])
            assert t != 0
            if t < 0:
                count += 1
    return count

timestart = time()
T = int(fin.readline())
for case in range(1, T+1):
    N = int(fin.readline())
    wires = list(map(int, fin.readline().split()) for i in range(N))
    result = Intranet(wires)
    print result
    fout.write("Case #%d: %s\n" % (case, result))
    
fin.close()
fout.close()
print "\nTime: %.4f" % (time() - timestart)
