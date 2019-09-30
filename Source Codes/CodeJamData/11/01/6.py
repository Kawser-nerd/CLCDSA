import sys

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    print "Case #%d:" % testNr ,
#    n = int(sys.stdin.readline())
    ms = []
    a = sys.stdin.readline().split()
    for i,e in enumerate(a) :
	if i%2==1 :
	    ms.append( ( a[i], int(a[i+1]) ) )
    p = {}
    p['O'] = 1
    p['B'] = 1
    steps = 0
    for i,(col,pos) in enumerate(ms) :
#	print "MOVING TO",(col,pos)
	now = p[col]
	time = abs(now-pos)+1
	steps += time
	p[col] = pos
#	print "CURRENTLY",p
	otherCol = 'O' if col=='B' else 'B'
	now = p[otherCol]
	target = now
	for (c,pos2) in ms[i+1:] :
	    if c==otherCol :
		target = pos2
		break
	time2 = abs(target-now)
	if time2<=time :
	    p[otherCol] = target
	else :
	    if target<now :
		p[otherCol] = now-time
	    elif target>now :
		p[otherCol] = now+time
	    else :
		pass
#	print (col,pos),p
#	print "TIME",steps
    print steps