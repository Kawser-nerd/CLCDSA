
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
    ls = map(float, nextline().split())
    ps = map(float, nextline().split())
    ps = [p/100. for p in ps]
    es = [(ls[i]/(1-ps[i]) - ls[i], N-i) for i in xrange(N)]
    es.sort(reverse=True)
    inds = [N-e[1] for e in es]
    
    print 'Case #%s:'%t, ' '.join(map(str,inds))

















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
