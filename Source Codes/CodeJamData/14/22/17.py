for tc in range(int(input())):
	A, B, K = (int(x)-1 for x in input().split())
	dp = [[-1]*8 for i in range(31)]

	def DP(pos, a, b, k):
		if pos < 0:
			return 1
		if dp[pos][a*4+b*2+k] == -1:
			dp[pos][a*4+b*2+k] = 0

			bita = 0 if (A & (1 << pos)) == 0 else 1
			bitb = 0 if (B & (1 << pos)) == 0 else 1
			bitk = 0 if (K & (1 << pos)) == 0 else 1
			for xa in range(2):
				for xb in range(2):
					if a == 0 and bita == 0 and xa == 1:
						continue
					if b == 0 and bitb == 0 and xb == 1:
						continue
					xk = xa & xb
					if k == 0 and bitk == 0 and xk == 1:
						continue

					na = 1 if xa < bita else a
					nb = 1 if xb < bitb else b
					nk = 1 if xk < bitk else k

					dp[pos][a*4+b*2+k] += DP(pos-1, na, nb, nk);

		return dp[pos][a*4+b*2+k]

	print('Case #{}: {}'.format(tc+1, DP(30, 0, 0, 0)))