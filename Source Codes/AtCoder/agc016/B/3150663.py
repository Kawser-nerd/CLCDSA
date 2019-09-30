n = int(input())
a = list(map(int, input().split()))
Min = min(a)
Max = max(a)
if Max - Min > 1:
	print("No")
elif Max == Min:
	if a[0] == n - 1 or a[0] <= n // 2:
		print("Yes")
	else:
		print("No")
else:
	c_M = a.count(Max)
	c_m = n - c_M
	if c_m < Max <= c_m + c_M // 2:
		print("Yes")
	else:
		print("No")