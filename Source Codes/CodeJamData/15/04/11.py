import math
import re

def solve(x,r,c):
	if x>=7:
		return "RICHARD"
	if (r*c)%x!=0:
		return "RICHARD"
	if max(r,c)<x:
		return "RICHARD"
	if min(r,c)<(x+1)/2:
		return "RICHARD"
	if max(r,c)==5 and min(r,c)==3 and x==5:
		return "RICHARD"
	if min(r,c)==x/2 and x!=2:
		return "RICHARD"
	return "GABRIEL"

inp = open("D-large.in","r")
out = open("D-large","w")
lines = inp.readlines()
for i in range(1,len(lines)):
	l = [int(x) for x in re.split(" ",lines[i])]
	out.write("Case #"+str(i)+": "+solve(l[0],l[1],l[2])+"\n")
out.close()
inp.close()
