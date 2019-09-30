#!/usr/bin/env python
# Python 2.6.1
# input from stdin, output to stdout

def debug(**a):
	print " ".join("%s=%s" % (k,v) for (k,v) in a.iteritems())

def read_ints():
	return [int(x) for x in raw_input().strip().split()]

def main():
	[T]=read_ints()
	for t in xrange(1,T+1):
		[R,k,N]=read_ints()
		g=tuple(read_ints())
		m=0
		h={g : (0,0)}
#		h=None
		r=1
		while r<=R:
			s=()
			while True:
				if len(g)>0 and sum(s)+g[0]<=k:
					s+=(g[0],)
					g=g[1:]
				else:
					break
			m+=sum(s)
			g+=s
			if h:
				if g in h:
					(pr,pm) = h[g]
					dr=r-pr
					dm=m-pm
					z=(R-r)/dr
					r+=z*dr
					m+=z*dm
#					debug(z=z)
					h=None
				else:
					h[g]=(r,m)
			r+=1
		print "Case #%d: %d" % (t,m)

if __name__=='__main__':
	main()