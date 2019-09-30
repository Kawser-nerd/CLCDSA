
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
    
    M,F,N = map(int, nextline().split())
    meals = [map(int, nextline().split()) for _ in xrange(N)]
    bmeals = []
    while meals:
        meals.sort()
        cheap = meals[0][0]
        cheapest = [m for m in meals if m[0]==cheap]
        cheapest.sort(reverse=True)
        best = cheapest[0]
        meals.remove(best)
        bmeals.append(best)
        day = best[1]
        meals = [m for m in meals if m[1]>day]
    
    bdays = 0
    bdels = -1
    
    def deldays(dels):
        global bdays, bdels
        m = M - dels*F
        if m <= 0: return 0
        tdays = 0
        day = -1
        for meal in bmeals:
            p,s = meal
            dd = s-day
            day = s
            most = int(m/p)
            most = min(most, dels*dd)
            if most==0: break
            tdays += most
            m -= most*p
        bdays = max(bdays, tdays)
        if bdays==tdays:
            bdels = dels
        
    for r in xrange(len(bmeals)+1):
        dp = F
        day = -1
        for p,s in bmeals[:r]:
            dd = s-day
            day = s
            dp += p*dd
        dels = int(M/dp)
        deldays(dels)
        deldays(dels+1)
        
#    for dels in xrange(1,2*M):
#        deldays(dels)
    
    print 'Case #%s:'%t, bdays

















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
