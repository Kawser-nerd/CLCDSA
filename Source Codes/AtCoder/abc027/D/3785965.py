S = input()
dp = [] 
cc = 0
Mc = 0
hs = 0
 
for st in S:
	if st == 'M':
		Mc += 1
	elif st == '+':
		hs += Mc
	else:
		hs -= Mc

cc = 0

S = S[::-1]
for st in S:
	if st == 'M':
		dp.append(cc)
	elif st == '+':
		cc += 2
	else:
		cc -= 2

dp.sort()
if dp:
	a = sum(dp[Mc // 2:])
	print(a - hs)
else:
	print(0)