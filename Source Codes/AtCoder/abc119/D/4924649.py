import bisect

def calc_distance(frm, x, y):
	return min(abs(frm - x), abs(frm - y) ) + abs(x - y)

def calc_2points(frm, us):
	idx = bisect.bisect_left(us, frm)
	return us[idx - 1], us[idx]

def calc_min(ss, ts, x):
	s1, s2 = calc_2points(x, ss)
	t1, t2 = calc_2points(x, ts)
	ans = min(calc_distance(x, s1, t1), calc_distance(x, s1, t2), calc_distance(x, s2, t1), calc_distance(x, s2, t2))
	return ans

INF = 10 ** 20
a, b, q = list(map(int, input().split()))
ss = [-INF] + [int(input()) for _ in range(a)] + [INF]
ts = [-INF] + [int(input()) for _ in range(b)] + [INF]
xs = [int(input()) for _ in range(q)]

for x in xs:
	print(calc_min(ss, ts, x))