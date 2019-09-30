def main(s):
	y = [0,31,28,31,30,31,30,31,31,30,31,30,31]
	if (s[0] % 4 == 0 and s[0] % 100 != 0) or (s[0] % 400 == 0):
		y[2] += 1
	while True:
		if s[1] == 1 and s[2] == 1:
			break
		if s[0] % (s[1]*s[2]) == 0:
			break
		s[2] += 1
		if s[2] > y[s[1]]:
			s[1] = max(1, (s[1]+1) % 13)
			s[2] = 1
			if s[1] == 1:
				s[0] += 1
	s[1] = ("0" if s[1] < 10 else "") + str(s[1])
	s[2] = ("0" if s[2] < 10 else "") + str(s[2])
	print("{}/{}/{}".format(s[0],s[1],s[2]))
	return
main(list(map(int, input().split("/"))))