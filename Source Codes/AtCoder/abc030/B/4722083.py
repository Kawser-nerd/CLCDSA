n,m = map(int, input().split())
n = n%12 * 30 + m/2
m = m * 6
a = m - n
if abs(a) < 180:
	print(abs(a))
else:
	print(360-abs(a))