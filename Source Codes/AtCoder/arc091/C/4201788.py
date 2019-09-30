n, a, b = map(int, input().split())
if a+b-1 > n or a*b < n:
	print(-1)
elif b == 1:
	print(*list(range(1, n+1)))
else:
	ans = list(range(n-a+1, n+1))
	num = b-1
	mod = n-a - (n-a)//(b-1) * (b-1)
	size1 = (n-a)//(b-1)
	size2 = size1 + 1
	mi = n-a
	for i in range(num):
		if i < num-mod:
			ans += list(range(mi - size1 + 1, mi + 1))
			mi = mi - size1
		else:
			ans += list(range(mi - size2 + 1, mi + 1))
			mi = mi - size2
	print(*ans)