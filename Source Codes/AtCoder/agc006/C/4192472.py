n = int(input())
x = list(map(int, input().split()))
g = [x[i+1]-x[i] for i in range(n-1)]
m, k = map(int, input().split())
A = list(map(int, input().split()))
t = list(range(n-1))
for a in A:
	t[a-2], t[a-1] = t[a-1], t[a-2]
s = list(range(n-1))
while k > 0:
	if k&1:
		s = [s[t[i]] for i in range(n-1)]
	t = [t[t[i]] for i in range(n-1)]
	k >>= 1
new_g = [g[s[i]] for i in range(n-1)]
ans = [x[0]]
for i in range(n-1):
	ans.append(ans[-1] + new_g[i])
print(*ans, sep="\n")