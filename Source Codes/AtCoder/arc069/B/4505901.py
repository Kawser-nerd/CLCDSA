#ARC069D
N=int(input())
S=input()
def NoSW(a):
	if a=='S':
		return 'W'
	else: #a=='W'
		return 'S'
def NoOX(a):
	if a=='o':
		return 'x'
	else: #a=='x'
		return 'o'
C=['' for i in range(N)]
for a in ['S','W']: #assumption1
	for b in ['S','W']:#assumption2
		C[0]=a
		C[1]=b
		for i in range(1,N-1):
			boo=0 if C[i]=='W' else 1
			if boo==(S[i]=='o'):
				C[i+1]=C[i-1]
			else:
				C[i+1]=NoSW(C[i-1])
		#final check
		boo=1 if (S[0]=='o') == (C[0]=='S') else 0
		if boo != (C[N-1]==C[1]):
			continue
		boo=1 if (S[N-1]=='o') == (C[N-1]=='S') else 0
		if boo != (C[N-2]==C[0]):
			continue
		print(''.join(C))
		exit()
print(-1)