
import sys
import logging

# Work out input and output file names
if len(sys.argv) > 1:
    sampledata = False
    infname = sys.argv[1]
else:
    sampledata = True
    scriptname = sys.argv[0]
    problemletter = scriptname[:scriptname.index('.')]
    infname = problemletter + '-example.in'
outfname = infname[:infname.index('.')] + '.out'

# Set up input
with open(infname) as f:
    text = f.read()
lines = text.splitlines()
linesiter = iter(lines)
nextline = linesiter.next

# Set up output
ofile = open(outfname, 'w')
sys.stdout = ofile

# Set up logging

# ^^^^^^^^^^^^^^^^^^^
# Template code above
#####################




T = int(nextline())


for t in range(1, T+1):
    
    N = int(nextline())
    
    # dist, len, besthold length
    vs = [map(int,nextline().split())+[0] for _ in xrange(N)]
    dst = int(nextline())
    
    reach = 0
    vs[0][2] = vs[0][0]
    
    while vs:
        v = vs.pop(0)
        l = min(v[1], v[2])
        reach = max(reach, v[0]+l)
        for ov in vs:
            if ov[0] <= v[0]+l:
                ov[2] = max(ov[2], ov[0]-v[0])
            else:
                break
        
    print 'Case #%s:'%t, 'YES' if reach >= dst else 'NO'

















#####################
# Template code below
# vvvvvvvvvvvvvvvvvvv

sys.stdout = sys.__stdout__
ofile.close()
if sampledata:
    base = problemletter+'-example.'
    outfile = base+'out'
    rightfile = base+'right'
    out = open(outfile).read()
    right = open(rightfile).read()
    if out==right:
        print 'Congrats, your output matches sample output'
    else:
        print 'OUTPUT MISMATCH'
        import os
        os.system('diff %s %s'%(outfile,rightfile))
