from collections import *
p,i=print,input
q=lambda *a:(p('?',*a),i()=='Y')[1]
A,B=map(int,i().split())
r=range(A+B)
c=deque(r)
if A>B:
	while len(c)>2:c.extendleft(([],[c[-2]])[q(c.pop(),c.pop())])
	p('!',''.join(str(int(q(c[0],d))) for d in r))
else: p('Impossible')