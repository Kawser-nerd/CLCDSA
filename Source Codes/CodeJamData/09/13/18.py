
from scipy.special import gammaln,exp
from scipy import comb
import sys
#def fact(n):
#	if n <= 1: return 1
#	else: return n*fact(n-1)

def factln(n):
	return gammaln(n+1)

def prob_old(c,n,j,k):
	pi = k - j		# how many new marbles to pick
	po = c - pi		# how many old marbles to pick
	
	lnp = factln(n-c) + factln(j) + factln(n-j)
	lnp -= factln(n) + factln(j-po) + factln(n-j-pi)
	p = exp(lnp)
	return p

def prob(c,n,j,k):
	pi = k - j		# how many new marbles to pick
	po = c - pi		# how many old marbles to pick

	old_count = j
	new_count = n-j
	
	return comb(old_count,po)*comb(new_count,pi)/comb(n,c)

def solve(c,n):
	# Probability of having c of the cards
	p0 = [0 for x in range(n+1)]
	p0[0] = 1.0
	p1 = [0.0 for x in range(n+1)]

	sum = 0.0
	nstep = 0

	prob_prev = 0.0
	# steps

	while p0[n] < 0.999999:
		for j in range(n+1): p1[j] = 0.0
		# Start with p0[j] and find contribution to p1[k]
		for j in range(n+1):
			for k in range(j,n+1):
				if k - j > c: break
				# j = marbles already seen
				# k = marbles we will have seen
				# n = total marbles
				# end with k marbles old

				p = prob(c,n,j,k)
				p1[k] += p0[j]*p
		#print p1
		for j in range(n+1): p0[j] = p1[j]

		nstep += 1
		sum += (p0[n] - prob_prev)*(nstep)
		prob_prev = p0[n]
	
	#print nstep
	return sum
		


	# average on probability of having the last entry

fn = sys.argv[1]

f = open(fn,'r')

t = int(f.readline())

#print solve(2,3)
#exit()
for i in range(t):
	n,c = [int(x) for x in f.readline().split()]

	s = solve(c,n)

	print "Case #%d: %.8f"%(i+1,s)
	sys.stdout.flush()

