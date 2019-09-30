
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


let = 'oieastbg'
num = '01345789'
letnum = dict(zip(let,num))


T = int(nextline())


for t in range(1, T+1):
    
    k = int(nextline())
    s = nextline()
    pairs = set()
    for i, c in enumerate(s):
        if i==0: continue
        b = s[i-1]
        pairs.add(b+c)
        if b in letnum:
            pairs.add(letnum[b]+c)
        if c in letnum:
            pairs.add(b+letnum[c])
        if b in letnum and c in letnum:
            pairs.add(letnum[b]+letnum[c])
    out = []
    
    while pairs:
        b,c = pairs.pop()
        s = [b,c]
        while True:
            okay = [p for p in pairs if p[0]==s[-1]]
            good = [p for p in okay if any(op[0]==p[-1] and p!=op for op in pairs)]
            if good:
                p = good.pop()
            elif okay:
                p = okay.pop()
            else:
                break
            pairs.remove(p)
            s.append(p[-1])
        while True:
            okay = [p for p in pairs if p[1]==s[0]]
            good = [p for p in okay if any(op[1]==p[0] and p!=op for op in pairs)]
            if good:
                p = good.pop()
            elif okay:
                p = okay.pop()
            else:
                break
            pairs.remove(p)
            s.insert(0, p[0])
        out.extend(s)
    
            
    print 'Case #%s:'%t, len(out)
#    print ''.join(out)

















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
