def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

test=int(raw_input())
for i in xrange(1,test+1):
	lista = raw_input()
	(n, x, y) = lista.split(' ')
	x = int(x)
	y = int(y)
	lista = raw_input()
	res = -1
	for wynik in xrange(x ,y +1):
		ok = True
		for liczba in lista.split(' '):
			licz = int(liczba);
			if licz % wynik != 0 and wynik % licz != 0:
				ok = False
				break
		if ok:
			res = wynik
			break


	if res == -1:
		print "Case #%d: NO" % i
	else:
		print "Case #%d: %d" % (i, res)
	
	
