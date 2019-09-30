# First Run this, and get result.py (uses about 1~2 hours)
'''
maxLen = 100
ans = [0,1,2,3]
for i in range(1, 2**(maxLen/4)):



	s = ""
	t = i
	while t > 0:
		s = str(t%2) + s
		t /= 2

	t = i
	while t % 2 == 0:
		t /= 2
	if t == 1:
		print len(s)
	

	x = eval(str(s) + str(s)[::-1])
	if str(x*x) == str(x*x)[::-1]:
		ans.append(x)
	for t in range(3):
		x = eval(str(s) + str(t) + str(s)[::-1])
		if str(x*x) == str(x*x)[::-1]:
			ans.append(x)

for i in range(2, maxLen-1):
	s = eval("2" + "0" * (i-2) + "2")
	ans.append(s)
	if i%2 == 1:
		s = eval("2" + "0" * ((i-3)/2) + "1" + "0" * ((i-3)/2) + "2")
		ans.append(s)

ans.sort()
content = "ans = ["
for i in range(len(ans)):
	content += str(ans[i] ** 2)
	if i == len(ans)-1:
		content += "]\n"
	else:
		content += ", "
open("result.py", "w").write(content)
'''
from result import *

def searchNotLargeThan(x):
	if x < ans[0]:
		return 0
	L, R = 0, len(ans)
	while R - L > 1:
		M = (L + R) / 2
		if ans[M] <= x:
			L = M
		else:
			R = M
	return L+1

content = ""
inputs = open("in.txt").read().split("\n")
for i in range(1, len(inputs)):
	L, R = eval(inputs[i].replace(' ', ','))
	content += "Case #" + str(i) + ": " + str(searchNotLargeThan(R) - searchNotLargeThan(L-1)) + "\n"
open("out.txt", "w").write(content)
