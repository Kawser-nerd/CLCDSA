
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
    
    pairs = [[0, map(int,nextline().split())] for _ in range(N)] 
    
    turns = 0
    stars = 0
    
    toobad = False
    pairs.sort()
    while pairs[0][0] < 2:
        better = False
        for pair in pairs:
            if pair[0] == 2: break
            if pair[1][1] <= stars:
                better = True
                turns += 1
                stars += 2 - pair[0]
                pair[0] = 2
        if not better:
            star0 = [pair for pair in pairs if pair[0]==0]
            poss = [pair for pair in star0 if pair[1][0] <= stars]
            if len(poss) == 0:
                toobad = True
                break
            poss.sort(key=lambda p: p[1][1], reverse=True)
            pair = poss[0]
            turns += 1
            stars += 1
            pair[0] = 1
        pairs.sort()
    
    if toobad:
        print 'Case #%s: Too Bad'%t
    else:
        print 'Case #%s:'%t, turns

















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
