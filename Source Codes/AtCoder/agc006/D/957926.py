# def makelist(n, m):
# 	return [[0 for i in range(m)] for j in range(n)]

N = int(input())
a = [0] + list(map(int, input().split()))

def check(n):
	b = [False]*(len(a))
	for i in range(1, len(a)):
		if a[i] >= n:
			b[i] = True
		else:
			b[i] = False

	r = int(1e9)
	l = int(1e9)
	rb = b[N]
	lb = b[N]
	for i in range(1, N):
		if lb == b[N-i]:
			l = i
			break
		else:
			lb = b[N-i]
		
	for i in range(1, N):
		if rb == b[N+i]:
			r = i
			break
		else:
			rb = b[N+i]
	if r == int(1e9) and l == int(1e9):
		if N % 2 == 1:
			return b[N]
		else:
			return not b[N]
	else:
		if r < l:
			return rb
		else:
			return lb

# ?????????????
def binarySearch(small, big):
	mid = (big + small) // 2
	if big - small <= 1:
		if check(small): return small
		else:            return big
	else:
		if not check(mid):
			return binarySearch(small, mid)
		else:
			return binarySearch(mid, big)

print(binarySearch(2, 2*N-2))