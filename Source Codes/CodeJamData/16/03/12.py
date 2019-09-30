import sys

N = 32
J = 500
s = "1" + ("0" * (N-2)) + "1"
print("Case #1:")
while (J > 0):
	a = []
	for base in list(range(2, 11)):
		num = int(s, base)
		i = 2
		while (i <= 1000000):
			if ((num % i) == 0):
				a.append(i)
				break
			i = i+1
		if (i > 1000000):
			break
	if (len(a) == 9):
		print(s + " " + str(a[0]) + " " + str(a[1]) + " " + str(a[2]) + " " + str(a[3]) + " " + str(a[4]) + " " + str(a[5]) + " " + str(a[6]) + " " + str(a[7]) + " " + str(a[8]))
		J = J-1
		sys.stderr.write(str(J) + " to go!\n")
	k = N-2
	while (s[k] == '1'):
		k = k-1
	s = s[:k] + "1" + ("0" * (N-2-k)) + "1"