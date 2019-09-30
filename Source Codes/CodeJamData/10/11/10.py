import sys

from math import *
from itertools import *
from collections import defaultdict

# http://blog.bjrn.se/2008/04/lexicographic-permutations-using.html
from next_permutation import *
# http://docs.python.org/library/itertools.html
from recipes import *
# http://code.activestate.com/recipes/119466-dijkstras-algorithm-for-shortest-paths/
from dijkstra import *
# http://code.activestate.com/recipes/123641-hopcroft-karp-bipartite-matching/
from matching import *

def lg(a) :
    sys.stderr.write(str(a)+"\n")

def drop(b) :
    n = len(b)
    for i,a in enumerate(b) :
	c = []
	for p in a :
	    if p!='.' :
		c.append(p)
	for j in range(n-len(c)) :
	    c = ['.'] + c
	b[i] = c
    return b

def findit(b,k) :
    n = len(b)
    m = defaultdict(int)
    for x in range(n) :
	for y in range(n) :
	    for c in ('R','B') :
		for d in ( (0,-1), (-1,-1),(-1,0),(-1,+1) ) :
		    if b[x][y]!=c :
			m[(x,y,d,c)] = 0
			continue
		    if (x+d[0],y+d[1],d,c) in m :
			m[(x,y,d,c)] = m[(x+d[0],y+d[1],d,c)] + 1
		    else :
			m[(x,y,d,c)] = 1

    q = defaultdict(list)
    for y in range(n) :
	for x in range(n) :
	    for c in ('R','B') :
		for d in ( (0,-1), (-1,-1),(-1,0),(-1,+1) ) :
		    q[c].append(m[(x,y,d,c)])
    rgood = False
    bgood = False
    if len(q['R'])>0 :
	rgood = max(q['R'])>=k
    if len(q['B'])>0 :
	bgood = max(q['B'])>=k

    qm = { (False,False):"Neither" , (False,True):"Blue" , (True,False):"Red" , (True,True):"Both" }
    return qm[(rgood,bgood)]

def solve(b,k) :
    b = drop(b)
    return findit(b,k)
    
t = int(sys.stdin.readline())
for testNr in range(1,t+1) :
    n,k = map(int,sys.stdin.readline().split())
    b = []
    for i in range(n) :
	a = list(sys.stdin.readline().strip())
	b.append(a)
    sol = solve(b,k)
    print "Case #%d:" % testNr ,
    print sol

