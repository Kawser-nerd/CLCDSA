N,A,B = map(int,input().split())
if A + B > N + 1 or A * B < N:
	print(-1)
	exit()
swap = False
if A < B:
	B,A = A,B
	swap = True

base = [i for i in range(1,A+1)]
rest = N - A
roop = (N + A - 1) // A
if roop == B:
	a = A + 1
	pre = []
	while a <= N:
		pre = [i for i in range(a, min(N+1, a+A))] + pre
		a += A
else:
	pre = [i for i in range(A+B-1, A, -1)]
	r = []
	a = A+B
	while a <= N:
	  r = [i for i in range(a, min(N+1, a+A-1))] + r
	  a += A-1
	pre = pre + r
ans = pre + base
if swap:
	ans = [N-i+1 for i in ans]
print(" ".join(map(str, ans)))