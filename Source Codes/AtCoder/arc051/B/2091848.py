K = int(input())
f = [0] * 42
f[0] = 1
f[1] = 1
for k in range(2,42):
	f[k] = f[k-1] + f[k-2]

print(f[K+1],f[K])