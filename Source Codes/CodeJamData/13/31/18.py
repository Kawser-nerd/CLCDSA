def solve(s,n):
	lastPos = 0
	j=0
	count = 0
	for i in range(len(s)):
		if not (s[i] in ["a","e","i","o","u"]):
			j+=1
		else:
			j=0
		if j>=n:
			count+=(i-(n-1)-lastPos+1)*(len(s)-i)
			#print count
			lastPos = i-(n-1)+1
	return count
for T in range(int(raw_input())):
	data = raw_input().split()
	s = data[0]
	n = int(data[1])
	res = 0
	res = solve(s,n)
	print "Case #%d: %d"%(T+1,res)
