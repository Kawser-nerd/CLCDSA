n = int(input())
s = []

for i in range(n):
	s.append(input())
	s[i] = list(s[i])
	s[i].reverse()
s.sort()

for i in range(n):
	s[i].reverse()
	print(''.join(s[i]))