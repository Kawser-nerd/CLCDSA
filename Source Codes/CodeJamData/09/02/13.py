#!/usr/bin/env python
import sys

def recolor(H,W,B,c,d):
	for i in range(int(H)):
		for j in range(int(W)):
			if(B[i][j] == c):
				B[i][j] = d;
	

def searchpath(W,H,A,B,i,j,c):
	cur = A[i][j];
	if(B[i][j] == ' '):
		B[i][j] = c;
		to,d1,d2 = 100000, -1,-1;

		if(i-1>=0 and A[i-1][j] < to):
			to,d1,d2 = A[i-1][j],i-1,j;
		if(j-1>=0 and A[i][j-1] < to):
			to,d1,d2 = A[i][j-1],i,j-1;
		if(j+1<W and A[i][j+1] < to):
			to,d1,d2 = A[i][j+1],i,j+1;
		if(i+1<H and A[i+1][j] < to):
			to,d1,d2 = A[i+1][j],i+1,j;

		if(to < cur):
			return searchpath(W,H,A,B,d1,d2,c);
		else:
			return chr(ord(c)+1);
		
	else:
		recolor(H,W,B,c, B[i][j]);
		return c;
	
	


def docase(nr):
	H,W = map(int, raw_input().split())
	A = [map(int, raw_input().split()) for i in range(int(H))]
	B = [[' ' for i in range(int(W))] for i in range(int(H))]

	#print A[0][0]
	c = 'a';
	b = False;
	
	for i in range(int(H)):
		for j in range(int(W)):
			if(B[i][j] == ' '):
				c = searchpath(W,H,A,B,i,j,c);

	print "Case #"+str(nr+1)+":"
	for i in range(int(H)):
		S = ''
		for j in range(int(W)):
			S = S + B[i][j] + ' ';
		print S
	

def main():
	for i in range(input()):
		docase(i)

if __name__ == "__main__":
    main()
