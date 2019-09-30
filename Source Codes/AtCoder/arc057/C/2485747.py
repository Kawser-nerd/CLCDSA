S = int(input().strip())

s1 = str(S**2)[::-1]+'0'*100
s2 = str((S+1)**2)[::-1]+'0'*100

def Get(d):
	top1 = int(s1[2*d:][::-1])
	top2 = int(s2[2*d:][::-1])
	if int(s1[:2*d][::-1] or 0):
		top1 += 1
	if not int(s2[:2*d][::-1] or 0):
		top2 -= 1
	return top1, top2

ad = 0
while True:
	l, r = Get(ad+1)
	if l>r: break
	ad += 1

print(Get(ad)[0])