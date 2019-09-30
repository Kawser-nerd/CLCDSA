def power(a, b):
	if b == 0:
		return 1
	elif b == 1:
		return a % 1000000007
	elif b % 2 == 0:
		return (power(a, b//2) ** 2) % 1000000007
	else:
		return (power(a, b//2) ** 2 * a) % 1000000007
 
def divide(a, b):
	return (a * power(b, 1000000005)) % 1000000007

N = int(input())

fac_lim = N
fac = [None]*(fac_lim+1)
fac[0] = 1
for i in range(fac_lim):
    fac[i+1] = fac[i] * (i+1)
    fac[i+1] = fac[i + 1] % 1000000007

fs = [0] * (N+1)
fs[1] = fac[N]
for i in range(1,N):
    fs[i+1] = fs[i] + divide(fs[1], i+1)
    fs[i+1] %= 1000000007

A = [int(i) for i in input().split()]

ans = 0
for i in range(N):
    ans += (fs[i+1] + fs[N-i] - fs[1]) * A[i]
    ans %= 1000000007
print(ans)