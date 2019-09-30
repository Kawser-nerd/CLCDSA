import sys
def go():
	for tc in range(1,input()+1):
		N = 500
		print "Case #%d:" % tc
		m = {}
		S = map(int,raw_input().split())
		S = S[1:]
		A = {2**i:i for i in range(N)}
		s1 = 1
		sm = S[0]
		from random import sample, randint
		while 1:
			rn = randint(0,N-1)
			if s1&(1<<rn): sm-=S[rn]
			else: sm+=S[rn]
			s1 ^= (1<<rn)
			if sm in m and s1!=m[sm]: break
			m[sm]=s1
			if len(m)%65536==0: print >>sys.stderr,len(m)
		b = lambda n:[i for i,v in enumerate(bin(n)[::-1]) if v=='1']
		print " ".join(str(S[i]) for i in b(s1))
		print " ".join(str(S[i]) for i in b(m[sm]))

go()
