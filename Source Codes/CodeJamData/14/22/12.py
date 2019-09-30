T = input()
seen = {}

def solve(da, db, dk):

	maxlen = max([len(da), len(db), len(dk)])
	if maxlen == 0:
		return 0
	da = (maxlen - len(da)) * '0' + da
	db = (maxlen - len(db)) * '0' + db
	dk = (maxlen - len(dk)) * '0' + dk
	if (da, db, dk) in seen:
		return seen[(da, db, dk)]
	# print da, db, dk
	if dk == '0':
		if da == '0' and db == '0':
			ans = 1
			seen[(da, db, dk)] = ans
			return ans

		if da == '1' and db == '1':
			ans = 3
			seen[(da, db, dk)] = ans
			return ans
		ans = 2
		seen[(da, db, dk)] = ans
		return ans

	if dk == '1':
		ans = (int(da, 2) + 1) * (int(db, 2) + 1)
		seen[(da, db, dk)] = ans
		return ans

	if list(set(list(dk))) == ['1']:
		ans = (int(da, 2) + 1) * (int(db, 2) + 1)
		seen[(da, db, dk)] = ans
		return ans

	if dk[0] == '1':
		if da[0] == '0' and db[0] == '0':
			ans = solve(da[1:], db[1:], '1' * (maxlen - 1))
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '1' and db[0] == '1':
			# print 'case 2'
			ans = solve(da[1:], db[1:], dk[1:]) + (4 ** (maxlen - 1)) + solve(da[1:], '1' * (maxlen - 1), '1' * (maxlen - 1)) + solve('1' * (maxlen - 1), db[1:], '1' * (maxlen - 1))
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '0' and db[0] == '1':
			# print 'case 3'
			ans = solve(da[1:], '1' * (maxlen - 1), '1' * (maxlen - 1)) + solve(da[1:], db[1:], '1' * (maxlen - 1))
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '1' and db[0] == '0':
			# print 'case 4'
			ans = solve('1' * (maxlen - 1), db[1:], '1' * (maxlen - 1)) + solve(da[1:], db[1:], '1' * (maxlen - 1))
			seen[(da, db, dk)] = ans
			return ans
	if dk[0] == '0':
		# print 'case 2'
		if da[0] == '1' and db[0] == '1':
			# print 'case 5'
			ans = solve('1' * (maxlen - 1), '1' * (maxlen - 1), dk[1:]) + solve(da[1:], '1' * (maxlen - 1), dk[1:]) + solve('1' * (maxlen - 1), db[1:], dk[1:])
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '0' and db[0] == '0':
			# print 'case 6'
			ans = solve(da[1:], db[1:], dk[1:])
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '0' and db[0] == '1':
			# print 'case 7'
			ans = solve(da[1:], '1' * (maxlen - 1), dk[1:]) + solve(da[1:], db[1:], dk[1:])
			seen[(da, db, dk)] = ans
			return ans
		if da[0] == '1' and db[0] == '0':
			# print 'case 8'
			ans = solve('1' * (maxlen - 1), db[1:], dk[1:]) + solve(da[1:], db[1:], dk[1:])
			seen[(da, db, dk)] = ans
			return ans

for case in range(1, T + 1):
	ans = 0
	A, B, K = map(int, raw_input().split())
	da, db, dk = str(bin(A - 1))[2:], str(bin(B - 1))[2:], str(bin(K - 1))[2:]
	ans = solve(da, db, dk)


	print "Case #%d:" % case, ans
