import sys


def sim(comb,opp,invoke) :
    v = []
    for i,p in enumerate(invoke) :
	v.append(p)
	changed = True
	while changed :
	    changed = False
	    if len(v)>=2 :
		bi = "".join(v[-2:])
		rebi = bi[1]+bi[0]
	    else :
		bi = ''
		rebi = ''
	    if (bi in comb) :
	        v[-2:] = comb[bi]
		changed = True
	    elif (rebi in comb) :
		v[-2:] = comb[rebi]
		changed = True
	    # print v
	ps = set(v)
	# print "set",ps
	for bi in opp :
	    if bi[0] in ps and bi[1] in ps :
		v = []
    print "["+ ", ".join(v) + "]"

t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    print "Case #%d:" % testNr ,
    a = sys.stdin.readline().split()
    c = int(a[0])
    comb = {}
    opp = set()
    for i in range(1,c+1) :
	tri = a[i]
	comb[tri[:2]] = tri[2]
    d = int(a[c+1])
    a = a[c+1:]
    for i in range(1,d+1) :
	bi = a[i]
	opp.add(bi)
	opp.add(bi[1]+bi[0])
    n = int(a[d+1])
    v = a[d+2]
    assert n==len(v)
#    print comb
#    print opp
#    print n,v
    sim(comb,opp,v)
