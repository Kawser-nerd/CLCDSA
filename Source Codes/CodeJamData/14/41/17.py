for tc in range(int(input())):
	(N, X) = (int(x) for x in input().split())
	S = [int(x) for x in input().split()]
	S = list(reversed(sorted(S)))

	res = 0
	while S:
		a = S[0]
		found = False
		for i, b in enumerate(S):
			if i > 0 and a+b <= X:
				del S[i]
				del S[0]
				res += 1
				found = True
				break

		if not found:
			del S[0]
			res += 1

	print('Case #{}: {}'.format(tc+1, res))
