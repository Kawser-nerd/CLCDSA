n, m, k = map(int,input().split())
if not m+k-1 <= n <= m*k:
    print(-1)
    exit()

streak = [1]*k
streak[0] = m
i = 1
for increment in range(n-m-k+1):
    if streak[i] == m: i+= 1
    streak[i]+= 1
seq = list(range(n, 0, -1))

i = 0
for s in streak:
    subseq = seq[i:i+s]
    seq[i:i+s] = subseq[::-1]
    i+= s
print(*seq)