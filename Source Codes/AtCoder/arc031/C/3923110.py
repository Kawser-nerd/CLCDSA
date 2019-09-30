N = int(input())
*A, = map(int, input().split())

ans = 0

data = [0]*(N+1)
def get(k):
    s = 0
    while k:
        s += data[k]
        k -= k & -k
    return s
def add(k, x):
    while k <= N:
        data[k] += x
        k += k & -k


for i, a in enumerate(A):
    w = get(a)
    ans += min(N - a - (i - w), i - w)
    add(a, 1)

print(ans)