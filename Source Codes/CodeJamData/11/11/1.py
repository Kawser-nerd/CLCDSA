from fractions import gcd

for t in range(int(raw_input())):
	(N, Pd, Pg) = map(int, raw_input().split(' '))
	
	zmage = Pd
	porazi = 100 - Pd
	
	g = gcd(zmage, porazi)
	
	zmage /= g
	porazi /= g
	
	if zmage + porazi > N or (Pg == 100 and porazi > 0) or (Pg == 0 and zmage > 0):
		print 'Case #%d: Broken' % (t + 1)
	else:
		print 'Case #%d: Possible' % (t + 1)
	
