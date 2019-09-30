testSum = input()
for test in xrange(testSum):
	c, d, v = map(int, raw_input().split())
	coins = map(int, raw_input().split())
	ansCoins = []
	now = 0
	ans = 0
	i = 0
	while now < v:
		if i < len(coins) and (coins[i] <= now + 1 ):
			ansCoins.append(coins[i])
			now = now + coins[i] * c
			i = i + 1
		else:
			ansCoins.append(now + 1)
			ans = ans + 1
			now = now + (now + 1) * c
	print "Case #" + str(test + 1) + ":", ans
