n = int(input())
w = list(map(str, input().split()))

v = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
ans = 0

for i in range(n - 1):
	now = 0
	for j in range(3):
		if w[i] == v[j]:
			now = 1
			break
	
	ans += now

for j in range(3):
	v[j] += '.'
	if w[n - 1] == v[j]:
		ans += 1
		break

print(ans)