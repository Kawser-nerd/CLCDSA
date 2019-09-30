import sys

def solve(r,k,n,a) :
    next = {}
    income = {}
    for i in range(n) :
	j = i
	people = 0
	secondTime = False
	while True :
	    people += a[j]
	    if people>k or (j==i and secondTime) :
		people -= a[j]
		break
	    j += 1
	    j = j%n
	    secondTime = True
	next[i] = j
	income[i] = people
#	print i,j,people
    occ = set()
    pos = 0
    occ.add(pos)
    while True :
	pos = next[pos]
	if pos in occ :
	    break
	occ.add(pos)

    cross = pos
    length = 0
    sum = 0
    while True :
	length += 1
	sum += income[pos]
	pos = next[pos]
	if pos==cross :
	    break

#    print "cross "+str(cross)

    pos = 0
    firstSum = 0
    firstLength = 0
    while (pos!=cross) and (firstLength<r) :
	firstLength += 1
	firstSum += income[pos]
	pos = next[pos]
    
    if r<=firstLength :
	return firstSum

#    print "firstLength,firstSum",firstLength,firstSum
    
    aroundLength = r-firstLength
    times = aroundLength // length
    remainLength = aroundLength % length

    pos = cross
    remainSum = 0
    for i in range(remainLength) :
	remainSum += income[pos]
	pos = next[pos]

    final = firstSum + sum*times + remainSum
    return final

t = int(sys.stdin.readline())
for i in range(1,t+1) :
    a = map(int,sys.stdin.readline().split())
    assert len(a)==3
    (r,k,n) = a
    a = map(int,sys.stdin.readline().split())
    assert len(a)==n
    money = solve(r,k,n,a)
    print "Case #%d: %s" % ( i, money )
