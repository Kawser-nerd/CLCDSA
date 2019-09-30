MAXN = 1005

def GCD (a, b):
	while (b > 0):
		c = a % b
		a = b
		b = c
	return a

fi = open('warning.in','r')
T = int(fi.readline())
for iT in range(T):
	s = fi.readline()
	s2 = s.split()
	N = int(s2[0])
	data = []
	for i in range(N):
		data.append(int(s2[i+1]))
	a = []
	ac = 0
	for i in range(N):
		j = i + 1;
		while (j < N):
			a.append(abs(data[i] - data[j]))
			ac = ac + 1
			j = j + 1
	for i in range(ac-1):
		a[i+1] = GCD(a[i],a[i+1])
	T = a[ac-1]
	S = data[0] % T
	if (S > 0):
		S = T - S
	res = 'Case #' + str(iT+1) + ': ' + str(S)
	print(res)
