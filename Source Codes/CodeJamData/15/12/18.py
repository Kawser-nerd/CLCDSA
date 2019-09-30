import heapq

def ReadIn():
	t = int(input())
	for c in range(1, t + 1):
		m, n = [int(x) for x in input().split()]
		a = [int(x) for x in input().split()]
		yield c, n, a

def OK(n, a, guess):
	return sum([guess // x + 1 for x in a]) >= n

def Solve(n, a):
	if n <= len(a): return n
	lower = 0
	upper = max(a) * n
	while lower < upper:
		guess = (lower + upper + 1) // 2
		#print(lower, guess, upper)
		if OK(n, a, guess): upper = guess - 1
		else: lower = guess
	guess = lower
	heap = []
	remain = n
	for i, x in enumerate(a):
		num = guess // x + 1
		remain -= num
		heapq.heappush(heap, (num * x - guess, i))
	ret = heap[0][1]
	for r in range(remain):
		t, i = heapq.heappop(heap)
		heapq.heappush(heap, (t + a[i], i))
		ret = i
	return ret + 1

if __name__ == '__main__':
	for c, n, a in ReadIn():
		print('Case #%d: %d' % (c, Solve(n, a)))