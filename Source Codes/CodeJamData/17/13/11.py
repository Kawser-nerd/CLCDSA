#!python3

oo = 10**10

def solve(Hd0, Hd, Ad, Hk, Ak, B, D):
	ans = oo
	turn = 0
	while True:
		# print('B',turn)
		ans = min(ans, turn + solve_noD(Hd0, Hd, Ad, Hk, Ak, B))
		if Ak == 0 or D == 0: break
		turn += 1
		if Hd-max(Ak-D, 0) <= 0:
			if Hd == Hd0-Ak: break
			Hd = Hd0-Ak
		else:
			Ak, Hd = max(Ak-D, 0), Hd-max(Ak-D, 0)
		
		if Hd <= 0: break
	return ans

def solve_noD(Hd0, Hd, Ad, Hk, Ak, B):
	ans = oo
	turn = 0
	while True:
		# print('D',turn)
		ans = min(ans, turn + solve_noBD(Hd0, Hd, Ad, Hk, Ak))
		if Ad >= Hk or B == 0: break
		turn += 1
		if Hd-Ak <= 0:
			if Hd == Hd0-Ak: break
			Hd = Hd0-Ak
		else:
			Ad, Hd = Ad+B, Hd-Ak
		if Hd <= 0: break
	return ans

def solve_noBD(Hd0, Hd, Ad, Hk, Ak):
	turn = 0
	while True:
		# print('before', turn, 'Hd=%d, Ad=%d, Hk=%d, Ak=%d' % (Hd, Ad, Hk, Ak))
		turn += 1
		if Hk-Ad <= 0 or Hd-Ak > 0:
			Hk -= Ad
		else:
			if Hd0 - Ak == Hd: return oo
			Hd = Hd0
		if Hk <= 0: return turn
		Hd -= Ak
		if Hd <= 0: return oo

def main():
	ntest = int(input())
	for itest in range(ntest):
		Hd, Ad, Hk, Ak, B, D = map(int, input().strip().split(' '))
		ans = solve(Hd, Hd, Ad, Hk, Ak, B, D)
		print("Case #%d: %s" % (itest+1, 'IMPOSSIBLE' if ans == oo else ans))

if __name__ == '__main__':
	main()