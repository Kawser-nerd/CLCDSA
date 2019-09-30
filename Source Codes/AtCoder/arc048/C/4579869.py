N = int(input())
L = []
for _ in range(N):
	L.append(int(input()))
L.sort()

mod = 10**9+7
if N==1:
	print(pow(2, L[0], mod))
	exit()

def gcd(m, n):
    x = max(m, n)
    y = min(m, n)
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

M = []
for i in range(N-1):
	M.append(L[i+1]-L[i])

g = M[0]
for i in range(1,N-1):
	g = gcd(g, M[i])

print(pow(2, L[0]+(g+1)//2, mod))