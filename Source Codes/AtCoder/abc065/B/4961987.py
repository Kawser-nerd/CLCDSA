n = int(input())
a = [int(input()) for i in range(n)]
botan = a[0]
ans = -1
for i in range(n):
	if botan == 2:
		ans = i+1
		break
	botan = a[botan-1]

print(ans)