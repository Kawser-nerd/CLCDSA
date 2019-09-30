#!/usr/bin/python

import sys

S="welcome to code jam"
LS=len(S)

def main():
	n=int(raw_input().strip())
	for I in range(n):
		L=raw_input().strip()
		LL=len(L)
		# t[i][j] = number of ways to make first i chars of S using first j chars of L
		# t[i][j] = t[i][j-1]+t[i-1][j]       if S[i-1]==L[j-1]
		#         = t[i][j-1]                 if S[i-1]!=L[j-1]
		# t[0][*] = 1
		# t[*][0] = 0
		t=[[0]*(LL+1) for _ in range(LS+1)]
		for j in range(LL+1):
			t[0][j]=1
		for i in range(1,LS+1):
			for j in range(1,LL+1):
				if S[i-1]==L[j-1]:
					t[i][j]=t[i][j-1]+t[i-1][j]
				else:
					t[i][j]=t[i][j-1]
		sys.stdout.write("Case #%d: %04d\n" % (I+1,t[LS][LL]%10000))
#		print "\n".join(repr(tt) for tt in t)
		
if __name__=="__main__":
	main()