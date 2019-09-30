

# python 3.0





T = int(input())


for case in range(1,T+1):
	
	
	i = input()
	chars = list("1023456789abcdefghijklmnopqrstuvwxyz")
	oldnew = {}
	s = ""
	for ch in i:
		if ch not in oldnew:
			oldnew[ch] = chars.pop(0)
		s += oldnew[ch]
	
	base = len(oldnew)
	base = max(base,2)
	ans = int(s,base)
	
	print("Case #"+str(case)+": "+str(ans))












