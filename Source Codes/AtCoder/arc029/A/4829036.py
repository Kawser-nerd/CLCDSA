n = int(input())
t = sorted([int(input()) for i in range(n)],reverse = True)
a,b = 0,0
for i in t:
	if a <= b:
		a += i
	else:
		b += i
print(max(a,b))