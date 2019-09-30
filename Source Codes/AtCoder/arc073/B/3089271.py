n, W = map(int, input().split())
w0, v0 = map(int, input().split())
zero = [v0]
one = []
two = []
three = []

lzero, lone, ltwo, lthree = 1, 0, 0, 0

for _ in range(n - 1):
	w, v = map(int, input().split())
	if w == w0:
		zero.append(v)
		lzero += 1
	elif w == w0 + 1:
		one.append(v)
		lone += 1
	elif w == w0 + 2:
		two.append(v)
		ltwo += 1
	else:
		three.append(v)
		lthree += 1

zero.sort(reverse=True)
one.sort(reverse=True)
two.sort(reverse=True)
three.sort(reverse=True)

zero_sum = [0]
for i in range(len(zero)):
	zero_sum.append(zero_sum[-1] + zero[i])

one_sum = [0]
for i in range(len(one)):
	one_sum.append(one_sum[-1] + one[i])

two_sum = [0]
for i in range(len(two)):
	two_sum.append(two_sum[-1] + two[i])

three_sum = [0]
for i in range(len(three)):
	three_sum.append(three_sum[-1] + three[i])

ans = 0
for i in range(lzero + 1):
	for j in range(lone + 1):
		for k in range(ltwo + 1):
			for l in range(lthree + 1):
				wei = w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l
				val = zero_sum[i] + one_sum[j] + two_sum[k] + three_sum[l]
				if wei <= W and val > ans:
					ans = val

print(ans)