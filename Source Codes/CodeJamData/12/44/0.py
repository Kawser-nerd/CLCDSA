
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




def islucky(okay, bad, dst, at, nogo=None):
    if len(at)==1 and dst in at:
        return True
    else:
        dirs = {(-1,0),(0,+1),(+1,0)}
        if nogo is not None:
            dirs.remove(nogo)
        for dc,dr in dirs:
            newat = set()
            allgood = True
            for p in at:
                c,r = p
                np = (c+dc, r+dr)
                if np in bad:
                    allgood = False
                    break
                if np not in okay:
                    np = p
                newat.add(np)
            if not allgood:
                continue
            nogo = None
            if newat == at:
                continue
            if len(newat) == len(at):
                if dc != 0:
                    nogo = (-dc, dr)
            if islucky(okay, bad, dst, newat, nogo):
                return True
        return False


T = int(nextline())


for t in range(1, T+1):
    
    R,C = map(int,nextline().split())
    okay = set()
    caves = {}
    for r in range(R):
        line = nextline()
        for c, ch in enumerate(line):
            p = (c,r)
            if ch is not '#':
                okay.add(p)
                if ch is not '.':
                    caves[ch] = p
    
    print 'Case #%s:'%t

    for cave in sorted(caves.keys()):
        dst = caves[cave]
        at = {dst}
        new = {dst}
        while new:
            c,r = p = new.pop()
            for dc,dr in [(-1,0),(0,-1),(+1,0)]:
                 np = (c+dc,r+dr)
                 if np not in at and np in okay:
                    at.add(np)
                    new.add(np)
        bad = okay.difference(at)
        
        lucky = islucky(okay, bad, dst, at)
        
        print '%s: %s %s'%(cave, len(at), 'Lucky' if lucky else 'Unlucky')
    
    

















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
