n, z, w = map(int, input().split())
a = list(map(int, input().split()))

if n == 1:
	print(abs(w - a[0]))
else:
	print(max(abs(w - a[-1]), abs(a[-1] - a[-2])))