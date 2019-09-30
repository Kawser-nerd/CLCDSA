N, M = map(int, input().split())
S = input()
T = input()

def gcd(m, n):
    x = max(m, n)
    y = min(m, n)
    if y == 0:
        return x
    else:
        return gcd(y, x%y)

def lcm(m, n):
	return int(m*n/gcd(m,n))


L = lcm(N, M)
X = {}


for i in range(0,N):
	X[i*L//N] = S[i]
# print(X)
for i in range(0,M):
	if X.get(i*L//M) != None:
		if X[i*L//M] != T[i]:
			print(-1)
			exit()
	else:
		pass
print(L)