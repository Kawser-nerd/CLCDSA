def digitsum(x):
	s = 0
	while x > 0:
		s,x = s+x%10,x//10
	return s
l = list(range(1,10))
for i in range(10,100000):
	while digitsum(i)*l[-1] > digitsum(l[-1])*i:
		l.pop()
	l.append(i)
for length in range(6,20):
	for j in range(1000,10000):
		i = j*10**(length-4)+10**(length-4)-1
		while digitsum(i)*l[-1] > digitsum(l[-1])*i:
			l.pop()
		l.append(i)
k = int(input())
for i in range(0,k):
	print(l[i])