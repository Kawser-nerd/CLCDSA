R, C = map(int, input().split())
X, Y = map(int, input().split())
D, L = map(int, input().split())

def comb(n, r) :
	bunbo, bunsi = 1, 1
	
	for i in range(n-r+1, n+1) :
		bunsi *= i
	for i in range(1, r+1) :
		bunbo *= i
	return bunsi // bunbo

table = [[0 for j in range(Y+1)] for i in range(X+1)]
	
def calc(x, y) :
	if x * y  < D + L :
		return 0
		
	elif table[x][y] == 0 :
		if x > 0 : calc(x-1, y)
		if y > 0 : calc(x, y-1)
		
		sum = comb(x*y,D+L)*comb(D+L,L)
		
		for i in range(x+1) :
			for j in range(y+1) :
				sum -= (x-i+1)*(y-j+1)*table[i][j]
		table[x][y] = sum
		return sum
	else :
		return table[x][y]
		
print(calc(X,Y)*(R-X+1)*(C-Y+1) % 1000000007)