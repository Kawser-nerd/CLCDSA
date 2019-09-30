#!/usr/bin/env python
import sys

def countletter(S,l,L):
	ret = 0;
	for i in range(0,len(S)):
		if(S[i] == l or S[i] == L):
			ret +=1;
	return ret;
	
def choose(n, k):
   if 0 <= k <= n:
       ntok = 1
       ktok = 1
       for t in xrange(1, min(k, n - k) + 1):
          ntok *= n
          ktok *= t
          n -= 1
       return ntok // ktok
   else:
       return 0


M = "welcome to code jam"
N = "WELCOME TO CODE JAM"



def calc(C,S,p,s):
	retx = 0;
	
	if(p>18):
		return 1;
	
	if(C[s][p] != -1):
		return C[s][p];
		
	for i in range(s,len(S)):
		if(S[i] == M[p]):
			retx += calc(C,S,p+1,i+1);
	
	C[s][p] = retx;
	return retx;
		
def docase(nr):
	S = raw_input();
	C = [[-1 for i in range(0,19)] for j in range(0,len(S)+1)];
	R = calc(C,S,0,0) % 10000

	print "Case #"+str(nr+1)+": %04d" % R;
	

def main():
	for i in range(input()):
		docase(i)

if __name__ == "__main__":
    main()
