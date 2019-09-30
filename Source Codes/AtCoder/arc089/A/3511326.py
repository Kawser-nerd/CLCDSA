N = int(input())

t0, x0, y0 = 0, 0, 0
judge = "Yes"

for i in range(N):
	t, x, y = list(map(int, input().split()))
	if abs(x - x0) + abs(y - y0) <= t - t0 and (abs(x - x0) + abs(y - y0) - (t - t0)) % 2 == 0:
		x0 = x
		y0 = y
		t0 = t
	else:
		judge = "No"
		break

print(judge)