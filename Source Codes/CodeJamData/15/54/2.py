import math
import re

def solve(n,sums,freqs):
	s = []
	while len(sums)>1 or freqs[0]>1:
		if freqs[0]>1:
			m = 0
		else:
			m = sums[1]
		s.append(m)
		new_sums = []
		new_freqs = []
		while len(sums)>0:
			n = sums[0]
			freqs[0]-=1
			if freqs[0]==0:
				sums.pop(0)
				freqs.pop(0)
			i = sums.index(n+m)
			freqs[i]-=1
			if freqs[i]==0:
				sums.pop(i)
				freqs.pop(i)
			if n in new_sums:
				i = new_sums.index(n)
				new_freqs[i]+=1
			else:
				new_sums.append(n)
				new_freqs.append(1)
		sums = new_sums
		freqs = new_freqs
	string = ""
	for i in s:
		string+=str(i)
		string+=" "
	return string[:-1]


inp = open("D-small-attempt1.in","r")
out = open("D-small","w")
lines = inp.readlines()
i=1
count=1
while i<len(lines):
	print count
	n = [int(x) for x in re.split(" ",lines[i])]
	B = [int(x) for x in re.split(" ",lines[i+1])]
	C = [int(x) for x in re.split(" ",lines[i+2])]
	out.write("Case #"+str(count)+": "+solve(n,B,C)+"\n")
	i+=3
	count+=1
out.close()
inp.close()

