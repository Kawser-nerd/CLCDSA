h,w = map(int, input().split())
ans_min = 10 ** 10
if h % 3 == 0 or w % 3 == 0:
	ans_min = 0

else:
	for a in range(w+1):
		sa = h * a
		if h % 2 == 0:
			sb = (w-a) * (h // 2)
			sc = (w-a) * (h // 2)
		else:
			sb = (w-a) * (h // 2 + 1)
			sc = (w-a) * (h // 2)
		ans = max(sa,sb,sc) - min(sa,sb,sc)
		if ans_min > ans:
			ans_min = ans

	for a in range(h+1):
		sa = w * a
		if w % 2 == 0:
			sb = (h-a) * (w // 2)
			sc = (h-a) * (w // 2)
		else:
			sb = (h-a) * (w // 2 + 1)
			sc = (h-a) * (w // 2)
		ans = max(sa, sb, sc) - min(sa, sb, sc)

		if ans_min > ans:
			ans_min = ans
if ans_min > h:
	ans_min = h
if ans_min > w:
	ans_min = w
print(ans_min)