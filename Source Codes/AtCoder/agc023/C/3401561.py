MOD = (10 ** 9) + 7

list_size = 1000000

f_list = [1] * list_size
f_r_list = [1] * list_size

for i in range(list_size - 1):
	f_list[i + 1] = int((f_list[i] * (i + 2)) % MOD)

def power(n, x):
	if x == 1:
		return n
	elif x % 2 == 0:
		return power(int((n * n) % MOD), int(x / 2))
	else:
		return int((n * power(n, x - 1)) % MOD)

f_r_list[-1] = power(f_list[-1], MOD - 2)

for i in range(2, list_size + 1):
	f_r_list[-i] = int((f_r_list[-i + 1] * (list_size + 2 - i)) % MOD)

def factorial(i):
	if i == 0:
		return 1
	else:
		return f_list[i-1]

def comb(n, r):
	if n < r:
		return 0
	elif n == 0 or r == 0 or n == r:
		return 1
	else:
		return (((f_list[n - 1] * f_r_list[n - r - 1]) % MOD) * f_r_list[r - 1]) % MOD 

n = int(input())
ans = ((n - 1) * factorial(n - 1)) % MOD
for i in range(n - 2, (n + 1) // 2 - 1, -1):
	ans -= comb(i - 1, n - i - 1) * factorial(n - i - 1) * factorial(i)
	ans %= MOD
	#print(ans, cnt)
print(ans)