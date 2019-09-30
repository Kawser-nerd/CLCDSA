import sys

def pout(panel):
	for i in xrange(len(panel)):
		for j in xrange(len(panel[i])):
			sys.stdout.write(panel[i][j])
		print ""

def trans(panel):
	for i in xrange(len(panel)-1):
		if panel[i].count("#")==1: return False
		for j in xrange(len(panel[i])-1):
			if panel[i][j]=="#":
				if panel[i][j+1]!="#": return False
				if panel[i+1][j]!="#": return False
				if panel[i+1][j+1]!="#": return False
				panel[i][j]="/"
				panel[i][j+1]="\\"
				panel[i+1][j]="\\"
				panel[i+1][j+1]="/"
	for i in xrange(len(panel)):
		if panel[i].count("#")>0: return False
	return True
		
T=int(raw_input())
for t in xrange(T):
	data=raw_input().split()
	R=int(data[0])
	C=int(data[1])
	panel=[]
	for r in xrange(R):
		panel+=[[]]
		line=raw_input()
		for c in xrange(C):
			panel[r]+=line[c]
	#pout(panel)
	print "Case #%d: " %(t+1)
	if(trans(panel))==False: print "Impossible"
	else: pout(panel)