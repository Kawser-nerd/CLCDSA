R, C = map(int, input().split())
X, Y = map(int, input().split())
D, L = map(int, input().split())

MOD = 10 ** 9 + 7
DL = D+L

def comb(n, r) :
	if n <= 0 or r < 0 or n < r:
		return 0
		
	a, b = 1, 1
		
	for i in range(n-r+1, n+1) :
		a *= i
	for i in range(2, r+1) :
		b *= i
		
	return a // b

L0 = comb(X*Y,DL)
L1 = comb((X-1)*Y,DL)*2 + comb(X*(Y-1),DL)*2
L2 = comb((X-2)*Y,DL) + comb(X*(Y-2),DL) + comb((X-1)*(Y-1),DL)*4
L3 = comb((X-2)*(Y-1),DL)*2 + comb((X-1)*(Y-2),DL)*2
L4 = 0 if X == Y == 1 else comb((X-2)*(Y-2),DL)

print((R-X+1)*(C-Y+1)*(L0-L1+L2-L3+L4)*comb(DL, D) % MOD)