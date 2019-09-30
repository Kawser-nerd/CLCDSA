import bisect

def calc_distance(frm, x, y):
	#frm??x, y???????????????????
	return min(abs(frm - x), abs(frm - y) ) + abs(x - y)

def calc_both_end(frm, us):
	#??frm?????2?????
	#?????????????????2?
	if len(us) == 1:
		return us[0], us[0]

	idx = bisect.bisect_left(us, frm)
	if idx == 0:
		return us[0], us[1]
	elif idx == len(us):
		return us[len(us) - 2], us[len(us) - 1]
	else:
		return us[idx - 1], us[idx]

def find(ss, ts, x):
	s1, s2 = calc_both_end(x, ss)
	t1, t2 = calc_both_end(x, ts)
	ans = min(calc_distance(x, s1, t1), calc_distance(x, s1, t2), calc_distance(x, s2, t1), calc_distance(x, s2, t2))
	return ans

a, b, q = list(map(int, input().split()))
ss = [int(input()) for _ in range(a)]
ts = [int(input()) for _ in range(b)]
xs = [int(input()) for _ in range(q)]

for x in xs:
	print(find(ss, ts, x))