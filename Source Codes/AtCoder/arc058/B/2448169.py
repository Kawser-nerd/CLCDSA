BIG = (10 ** 9) + 7

f_list = [1] * 200000
f_r_list = [1] * 200000

for i in range(199999):
	f_list[i + 1] = int((f_list[i] * (i + 2)) % BIG)

def power(n, x):
	if x == 1:
		return n
	elif x % 2 == 0:
		return power(int((n * n) % BIG), int(x / 2))
	else:
		return int((n * power(n, x - 1)) % BIG)

f_r_list[-1] = power(f_list[-1], BIG - 2)

for i in range(2, 200001):
	f_r_list[-i] = int((f_r_list[-i + 1] * (200002 - i)) % BIG)

def comb(n, r):
	if n == 0 or r == 0 or n == r:
		return 1
	else:
		return (((f_list[n - 1] * f_r_list[n - r - 1]) % BIG) * f_r_list[r - 1]) % BIG 

h, w, a, b = map(int, input().split())

ans = 0

for i in range(h - a):
	ans = int((ans + int((comb(b + i - 1, b - 1) * comb(h + w - b - i - 2, w - b - 1)) % BIG)) % BIG)

print(int(ans))