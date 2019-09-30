import math
a,b = map(int,input().split())
n = math.floor(math.sqrt(a))+1
t = {}
ans = 1
for i in range(b+1,a+1):
	x = i
	for j in range(2,n):
		if j not in t:
			t[j] = 0
		while x%j == 0:
			x /= j
			t[j] += 1
		if x == 1:
			break
	if x != 1:
		if x not in t:
			t[x] = 0
		t[x] += 1
for k,v in t.items():
	ans *= (v+1)
	ans %= 1000000007
print(ans)