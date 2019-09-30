#!/usr/bin/python

import re
import sys

r=re.compile(r'(\([a-z]*\)|[a-z])')

def main():
	[l,d,n]=[int(x) for x in raw_input().strip().split()]
	words=[]
	for _ in range(d):
		words.append(raw_input().strip())
	for i in range(n):
		q=raw_input().strip()
		q=[c for c in r.split(q) if c]
		w=words
		for qq in q:
			w=[x[1:] for x in w if x[0] in qq]
		sys.stdout.write("Case #%d: %d\n" % (i+1,len(w)))
		
if __name__=="__main__":
	main()