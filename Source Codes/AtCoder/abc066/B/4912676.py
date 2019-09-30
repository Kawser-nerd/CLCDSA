S = input()
while 1:
	S = S[:-2]
	l = len(S)//2
	if S[:l]==S[l:]:
		print(l*2)
		break