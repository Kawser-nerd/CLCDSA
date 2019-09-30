#!/usr/bin/env python
import sys
import re

def main():
	L,D,N = raw_input().split();
	S = "";
	for i in range(int(D)):
		S = S + raw_input()+"\n";
	for j in range(int(N)):
		R = "^"+raw_input().replace("(","[").replace(")","]")+"$";
		m = re.findall(R,S,re.M)
		
		print "Case #"+str(j+1)+": "+str(len(m))

if __name__ == "__main__":
    main()
