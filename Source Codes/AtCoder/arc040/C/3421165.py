# -*- coding: utf-8 -*-
# ??????
a = int(input())
all = 0
fl = 0
x = a
for i in range(a):
	fl = 0
	b = input()
	if(a == 1):
		if(b[0]=="."):
			all = 1		
	elif(x == 0):
		x = a
	else:
		for j in reversed(range(x)):
			if(b[j]=="."):
				x = j
				all += 1
				fl = 1
				break
		if(fl == 0):
			x = a
		

# ??
print(all)