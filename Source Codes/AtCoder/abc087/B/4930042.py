a, b, c, x = [int(input())  for _ in range(4)]
ans = 0

for ia in range(a+1):
	for ib in range(b+1):
		for ic in range(c+1):
			if x == ia*500+ib*100+ic*50:
				ans += 1
print(ans)