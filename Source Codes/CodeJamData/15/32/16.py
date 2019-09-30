testSum = input()
for test in xrange(testSum):
	k, l, s = map(int, raw_input().split())
	a = raw_input()
	b = raw_input()
	minPos = len(b)
	for i in xrange(1, len(b)):
		if b[i:] == b[0:len(b) - i]:
			minPos = i
			break
	maxBa = (s - (len(b) - minPos)) / minPos

	dic = {}
	for ch in a:
		if dic.has_key(ch):
			dic[ch] = dic[ch] + 1
		else:
			dic[ch] = 1
	p = 1.0
	for ch in b:
		if dic.has_key(ch):
			p = p * dic[ch] / len(a)
		else:
			p = 0
			break
	expBa = p * (s - len(b) + 1)

	if expBa == 0:
		ans = 0
	else:
		ans = maxBa - expBa
	print "Case #" + str(test + 1) + ":", ans
