

def previously(x):
        #how to get to 10**x
        if x == 0:
                return 1
        elif x ==1:
                return 10
        else:
                x1 = (x+1)//2
                x2 = x//2
                gain = 10**x1 + 10**x2 -1
                return gain + previously(x-1)
                
        
def Next(N):
        # Whatever needs to be done
        count = 0
        s = str(N)
        x = len(s)
        if x < 2:
                return N
        tl = (x+1)//2
        tail = N % 10**tl
        if tail == 0:
                return 1 + Next(N-1)
        count += tail-1
        N -= tail - 1
        revstr = str(N)[::-1]
        count += 1
        if str(N) == revstr:
                count -= 1
        #print revstr
        count += int(revstr) % 10**tl
        #print count
        return count + previously(x-1)
        
####		

#input = open(r'./A-small-attempt1.in')
input = open(r'./A-large.in')
#input = open(r'./sample.in')

X = list(input)
C = int(X[0])
Y = [[int(j) for j in x.split()] for x in X[1:]]
#print Y

sol = []


j = 0 #counter if needed

#C=10
for i in xrange(C):
	s= Y[i][0]
	sol += [Next(s)]
	#print 'case ', i+1, 'done'
	if not i % 10: print 'case ', i+1, 'done'

tofile = True
if tofile:
        with open(r'./outputA.txt', 'w') as output:
                for i in range(len(sol)):
                        output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
        print sol

	
	
	
	
	
	
	
	
	
	
