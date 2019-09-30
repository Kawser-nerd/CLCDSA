a, b = map(int, input().split())
if a < b:
	ans = [["."] * 100 for _ in range(100)]
	ichi = (a - 1) // 50
	matsu = (a - 1) % 50

	for i in range(ichi):
		if i % 2 == 0:
			for j in range(0, 100, 2):
				ans[i][j] = "#"
		else:
			for j in range(1, 100, 2):
				ans[i][j] = "#"

	if matsu == 0:
		ans[ichi] = ["#"] * 100

	elif ichi % 2 == 0:
		for j in range(0, 2 * matsu - 1, 2):
			ans[ichi][j] = "#"
		for j in range(2 * matsu, 100):
			ans[ichi][j] = "#"
		ans[ichi + 1] = ["#"] * 100

	else:
		for j in range(1, 2 * matsu, 2):
			ans[ichi][j] = "#"
		for j in range(2 * matsu, 100):
			ans[ichi][j] = "#"
		ans[ichi + 1] = ["#"] * 100

	if ichi > 0:
		used = 50 * (ichi - 1) + matsu + 1
	else:
		used = 1
	remain = b - used
	r_ichi = remain // 50
	r_matsu = remain % 50

	for i in range(r_ichi):
		for j in range(0, 100, 2):
			ans[99 - 2 * i][j] = "#"

	for j in range(0, 2 * r_matsu, 2):
		ans[99 - 2 * r_ichi][j] = "#"

else:
	ans = [["#"] * 100 for _ in range(100)]
	ichi = (b - 1) // 50
	matsu = (b - 1) % 50

	for i in range(ichi):
		if i % 2 == 0:
			for j in range(0, 100, 2):
				ans[i][j] = "."
		else:
			for j in range(1, 100, 2):
				ans[i][j] = "."

	if matsu == 0:
		ans[ichi] = ["."] * 100

	elif ichi % 2 == 0:
		for j in range(0, 2 * matsu - 1, 2):
			ans[ichi][j] = "."
		for j in range(2 * matsu, 100):
			ans[ichi][j] = "."
		ans[ichi + 1] = ["."] * 100

	else:
		for j in range(1, 2 * matsu, 2):
			ans[ichi][j] = "."
		for j in range(2 * matsu, 100):
			ans[ichi][j] = "."
		ans[ichi + 1] = ["."] * 100

	if ichi > 0:
		used = 50 * (ichi - 1) + matsu + 1
	else:
		used = 1
	remain = a - used
	r_ichi = remain // 50
	r_matsu = remain % 50

	for i in range(r_ichi):
		for j in range(0, 100, 2):
			ans[99 - 2 * i][j] = "."

	for j in range(0, 2 * r_matsu, 2):
		ans[99 - 2 * r_ichi][j] = "."

print(100, 100)
print(*["".join(ans[i]) for i in range(100)], sep="\n")