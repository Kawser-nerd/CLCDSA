
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
    
    A,B = map(int, nextline().split())
    ps = map(float, nextline().split())
    
    best = 1+B+1
    pcorr = 1.0
    for i,p in enumerate(ps):
        pcorr *= p
        ncorr = (B-A) + 2*(A-i-1) + 1
        pwr = 1-pcorr
        nwr = ncorr + B + 1
        exp = pcorr*ncorr + pwr*nwr
        best = min(best,exp)
    
    print 'Case #%s:'%t, best

















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
