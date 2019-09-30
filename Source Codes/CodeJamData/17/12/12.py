#!python3

def pick(N, P, R, Q, size):
	for i in range(N):
		while True:
			# print('.')
			if len(Q[i]) == 0:
				return
			elif Q[i][0]*10 < R[i]*size*9:
				del Q[i][0]
			elif Q[i][0]*10 <= R[i]*size*11:
				break
			else:
				return
	# print('pick size', size)
	for i in range(N):
		del Q[i][0]
	return True

def solve(N, P, R, Q):
	for i in range(N):
		Q[i] = sorted(Q[i])

	# print(N, P, R, Q)
	size = 1
	cnt = 0
	while True:
		# print('.')
		if pick(N, P, R, Q, size):
			cnt += 1
		else:
			# print('.')
			for i in range(N):
				if len(Q[i]) == 0:
					return cnt
				else:
					a = Q[i][0]*10
					b = R[i]*11
					size = max(size, (a-1)//b+1)
			# print('update size', size)


def main():
	ntest = int(input())
	for itest in range(ntest):
		N, P = map(int, input().strip().split(' '))
		R = list(map(int, input().strip().split(' ')))
		Q = []
		for i in range(N):
			Q.append(list(map(int, input().strip().split(' '))))

		cnt = solve(N, P, R, Q)
		print("Case #%d: %d" % (itest+1, cnt))

if __name__ == '__main__':
	main()