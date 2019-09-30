import sys
def inpl(): return [int(i) for i in input().split()]
N, A, B = inpl()
rev = (A < B)
B ,A = sorted([B, A])
if B < -(-N//A) or A+B-1 > N:
    print(-1)
    sys.exit()
st = list(range(1,N+1))
if B == 1:
    ans = st
elif 2*A > N:
    ans = st[A:N-B+1] + st[N-1:N-B:-1] + st[0:A]
else:
    n = N//A
    x = B+(-N//A)+1
    ans = st[n*A:N] + st[(n-1)*A:n*A-x] + st[n*A-1:n*A-x-1:-1]
    for i in range(2,n+1):
        ans += st[(n-i)*A:(n-i+1)*A]
if rev:
    ans = [N+1-i for i in ans]
print(*ans)