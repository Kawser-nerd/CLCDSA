N,A,B = map(int,input().split(" "))

if N < (A + B - 1) or N > (A * B):
	print(-1)
	exit(0)

if B == 1 and A == N:
	seq = [str(n) for n in range(1,N+1)]
	print(' '.join(seq))
	exit(0)

seq = [str(num)for num in range(N-A+1,N+1)]
dif = (A * B - N)
div = A - (dif // (B-1))
mer = (dif % (B-1))

n = N - A
for i in range((B-1) - mer):
	for j in range(n-(div)+1,n+1):
		seq.append(str(j))
	n -= (div)

for i in range(mer):
	for j in range(n-div+2,n+1):
		seq.append(str(j))
	n -= (div - 1)

print(' '.join(seq))