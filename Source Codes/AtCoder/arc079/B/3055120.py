k = int(input())
if k == 0:
	print(2)
	print("1 1")
elif k == 1:
	print(2)
	print("2 0")
elif k <= 50:
	print(k)
	print(*[k for _ in range(k)])
else:
	print(50)
	div = k // 50 - 1
	mod = k % 50
	if mod == 0:
		ans = [50 + div] * 50
		print(*ans)
	else:
		ans = [50 + div + 50 - (mod - 1)] * mod + [50 + div - mod] * (50 - mod)
		print(*ans)