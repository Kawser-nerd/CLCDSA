

def solve():
	#f = open("in.txt", 'r')
	f = open("C-small-attempt2.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		[N, M, K]= [int(k) for k in f.readline().split()]
		a = min(N,M)
		b = max(N,M)
		if a == 1 or a == 2:
			print "Case #%i:" % (t+1), K
		elif a == 3:
			if b == 3:
				if K <= 4:
					res = K
				else:
					res = K-1
			elif b ==4:
				if K <= 4:
					res = K
				elif K <= 7:
					res = K-1
				else:
					res = K-2
			elif b == 5:
				if K <= 4:
					res = K
				elif K <= 7:
					res = K-1
				elif K <= 10:
					res = K-2
				else:
					res = K-3
			else: # b == 6
				if K <= 4:
					res = K
				elif K <= 7:
					res = K-1
				elif K <= 10:
					res = K-2
				elif K <= 13:
					res = K-3
				else:
					res = K-4
			print "Case #%i:" % (t+1), res
		else: # a = 4
			if b == 4:
				if K <= 4:
					res = K
				elif K <= 7:
					res = K-1
				elif K <= 9:
					res = K-2
				elif K <= 11:
					res = K-3
				else:
					res = K-4
			else: #b = 5
				if K <= 4:
					res = K
				elif K <= 7:
					res = K-1
				elif K <= 9:
					res = K-2
				elif K <= 11:
					res = K-3
				elif K <= 13:
					res = K-4
				elif K <= 15:
					res = K-5
				else:
					res = K-6
			print "Case #%i:" % (t+1), res

solve()