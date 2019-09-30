#

T = int( raw_input() )

for t in xrange( T ):
	
	string = raw_input()
	base = len(set(string))
	
	if base == 1: base = 2
	
	ans = 1
	
	d = {string[0]:1}
	
	next = 0
	
	for digit in string[1:]:
		
		ans *= base
		
		if digit in d:
			
			ans += d[digit]
		
		else:
			
			ans += next
			d[digit] = next
			next = 2 if next == 0 else next+1
	
	print "Case #%d: %d" % (t+1, ans)

