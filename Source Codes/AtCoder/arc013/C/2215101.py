N = int(input())
Touhu = []
for i in range(N):
	X, Y, Z = map(int,input().split())
	M = int(input())
	x = [0] * M
	y = [0] * M
	z = [0] * M
	for j in range(M):
		x[j], y[j], z[j] = map(int,input().split())
	Touhu += min(x), min(y), min(z)
	Touhu += X - max(x) - 1, Y - max(y) - 1, Z - max(z) - 1

res = 0
for nim in Touhu:
	res ^= nim

print("WIN" if res else "LOSE")