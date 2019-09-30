import math
import re

d={("1","1"):("1",0), ("1","i"):("i",0), ("1","j"):("j",0), ("1","k"):("k",0), ("i","1"):("i",0), ("i","i"):("1",1), ("i","j"):("k",0), ("i","k"):("j",1), ("j","1"):("j",0), ("j","i"):("k",1), ("j","j"):("1",1), ("j","k"):("i",0), ("k","1"):("k",0), ("k","i"):("j",0), ("k","j"):("i",1), ("k","k"):("1",1)}

def multiply((a,m),(b,n)):
	c = d[(a,b)][0]
	o = (m + n + d[(a,b)][1]) % 2
	return (c,o)

def first(array,a):
	for i in range(4):
		if a[i] in array:
			for k in range(len(array)):
				if array[k]==a[i]:
					return (i,k)

def last(array,b,x):
	for i in range(x-1,x-5,-1):
		if b[i%4] in array:
			for k in range(len(array)-1,-1,-1):
				if array[k]==b[i%4]:
					return (i,k)

def solve(x,string):
	array = [("1",0)]*len(string)
	for i in range(1,len(string)):
		array[i]=(multiply(array[i-1],(string[i-1],0)))
	prod = multiply(array[-1],(string[-1],0))
	if prod[0]=="1":
		if prod[1]==0:
			return "NO"
		elif x%2==0:
			return "NO"
	elif x%4!=2:
		return "NO"
	a = [("i",0)]*4
	a[1] = multiply(a[0],prod)
	a[2] = multiply(a[1],prod)
	a[3] = multiply(a[2],prod)
	b = [("k",0)]*4
	b[1] = multiply(b[0],prod)
	b[2] = multiply(b[1],prod)
	b[3] = multiply(b[2],prod)
	f = first(array,a)
	l = last(array,b,x)
	if f<l:
		return "YES"
	return "NO"

inp = open("C-large.in","r")
out = open("C-large","w")
lines = inp.readlines()
for i in range(len(lines)/2):
	x = int(re.split(" ",lines[2*i+1])[1])
	string = lines[2*i+2][:-1]
	out.write("Case #"+str(i+1)+": "+solve(x,string)+"\n")
out.close()
inp.close()
