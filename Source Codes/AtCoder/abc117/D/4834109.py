N,K = list(map(int,input().split()))
A = list(map(int,input().split()))

memo = [0 for i in range(65)]
AA = [i for i in A]
for i in AA:
	r = 0
	while i > 0:
		if((i & 1) == 1):
			memo[r] = memo[r] + 1
		i = i // 2
		r = r + 1
res = 0
for i in range(50):
	if 2*memo[i] < N:
		res = res + (1 << i)
d = 51
while res > K:
	if ((res >> d) & 1) == 1 and ((K >> d) & 1) == 0:
		res = res ^ (1 << d)
	d = d - 1
    
ans = 0
for i in A:
	ans = ans + (res ^ i)
print(ans)