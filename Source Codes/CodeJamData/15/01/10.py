import math
import re

def solve(string):
	s = 0
	t = 0
	for i in string:
		t = t + 1 - int(i)
		s = max(s,t)
	return(s)

inp = open("A-large.in","r")
out = open("A-large","w")
lines = inp.readlines()
for i in range(1,len(lines)):
	string = re.split(" ",lines[i])[1][:-1]
	out.write("Case #"+str(i)+": "+str(solve(string))+"\n")
out.close()
inp.close()
