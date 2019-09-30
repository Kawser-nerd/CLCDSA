N=int(input())
Info=[list(map(int,input().split(' '))) for i in range(N-1)] #[[C S F] [C S F] ...]
C=[info[0] for info in Info]
S=[info[1] for info in Info]
F=[info[2] for info in Info]

def gotoN(start): #start??????????
	global C,S,F
	if start==N:
		return 0
	else:
		stn = start
		t = S[stn-1]
		while stn < N:
			t = max(((t-1)//F[stn-1]+1)*F[stn-1], S[stn-1])+C[stn-1]
			stn += 1
		return t

for i in range(1,N+1):
	print(gotoN(i))