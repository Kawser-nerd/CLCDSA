#!/usr/bin/python

import sys

INF = 1000000

def main():
	n=int(raw_input().strip())
	for i in range(n):
		[h,w]=[int(x) for x in raw_input().strip().split()]
		m=[[INF]*(w+2)]+[[INF]+[int(x) for x in raw_input().strip().split()]+[INF] for _ in range(h)]+[[INF]*(w+2)]
		gr={}
		ss=[]
		for r in range(h):
			for c in range(w):
				br=r
				bc=c
				for (dr,dc) in [(r-1,c),(r,c-1),(r,c+1),(r+1,c)]:
					if m[br+1][bc+1]>m[dr+1][dc+1]:
						br=dr
						bc=dc
				if br==r and bc==c:
					ss.append((r,c))
				else:
					gr.setdefault((br,bc),[]).append((r,c))
		sm={}
		def dosm(s,v):
			sm[v]=s
			for vv in gr.setdefault(v,[]):
				dosm(s,vv)
		for s in ss:
			dosm(s,s)
		nl='a'
		smm={}
		sys.stdout.write("Case #%d:\n" % (i+1))
		for r in range(h):
			for c in range(w):
				s=sm[(r,c)]
				if s not in smm:
					smm[s]=nl
					nl=chr(ord(nl)+1)
				sys.stdout.write(smm[s])
				if c<w-1:
					sys.stdout.write(' ')
				else:
					sys.stdout.write('\n')

if __name__=="__main__":
	main()