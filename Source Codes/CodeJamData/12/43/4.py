
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

sys.setrecursionlimit(3000)


class Impossible(Exception):
    pass

top = 10**9

def hites(aims):
    if len(aims)==0:
        return []
    elif len(aims)==1:
        return [0]
    else:
        hs = []
        a = aims[0]
        if not (1 <= a < len(aims)):
            raise Impossible()
        before = aims[1:a+1]
        after = aims[a:]
        bhs = hites(before)[:-1]
        bn = len(bhs)
        bhs = [h - (bn-i) for i, h in enumerate(bhs)]
        ahs = hites(after)
        hs = [0] + bhs + ahs
        return hs


T = int(nextline())


for t in range(1, T+1):
    
    N = int(nextline())
    aims = map(int, nextline().split())
    aims = [a-1 for a in aims]  # 0-index
    aims = [a-i for i,a in enumerate(aims)] # express as offset
    aims.append(0)
    print 'Case #%s:'%t,
    try:
        hs = hites(aims)
        hs = [top+h for h in hs]
        print ' '.join(map(str,hs))
    except Impossible:
        print 'Impossible'

















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
