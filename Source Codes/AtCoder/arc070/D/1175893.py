import collections,sys
p=print
def ask(x,y):
	p('?',x,y)
	return input()=='Y'
A,B=map(int,input().split())
r=range(A+B)
if A<=B:
	p('Impossible')
	sys.exit()
c=collections.deque(r)
while len(c)>2:
	x,y=c.pop(),c.pop()
	if ask(x,y):
		c.appendleft(y)
p('!',''.join(str(int(ask(c[0],i))) for i in r))