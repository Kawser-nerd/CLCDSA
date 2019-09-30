                
        
def Next(s, N):
        # Whatever needs to be done
        # primitive case: two hikers
        D = []
        M= []
        for e in s:
                d, h, m = e
                for i in range(h):
                        D.append(d)
                        M.append(m+i)

        arrivals = [M[i]*(360.0-D[i])/360.0 for i in range(len(M))]
        allreturns = [arrivals[i]+M[i] for i in range(len(M))]
        oldreturns = allreturns
        H = len(arrivals)
        for j in range(1,H):
                nextreturns = [oldreturns[i]+M[i] for i in range(len(M))]
                oldreturns = nextreturns
                allreturns += nextreturns
        arrivals.sort()
        allreturns.sort()
        if max(arrivals) < min(allreturns):
                return 0
        #print arrivals, allreturns
        # all times are + epsilon
        r = H
        for a in arrivals:
                returnpenalty =  sum(1 for x in allreturns if x <= a)
                arrivalpenalty = sum(1 for x in arrivals if x > a)
                number = arrivalpenalty + returnpenalty
                if number < r:
                        r = number
        return r
        
        
####		

input = open(r'./C-small-2-attempt2.in')
#input = open(r'./C-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[int(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []



j = 0
i= 0

#C=10
while i < C:
	D = Y[j][0]
	s= Y[j+1:j+D+1]
	j += D+1
	i += 1
	sol += [Next(s, D)]
	#print D, s
	#print 'case ', i, 'done'
	if not i % 10: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputC.txt', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
