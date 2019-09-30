N, Q = map(int, input().split())

d = [1] * (N+1)

for i in range(Q):
    l, r = map(int, input().split())
    l -= 1
    d[r] *= -1
    d[l] *= -1

now = 0
for i in range(N):
    if d[i] == -1:
        now = 1 - now

    print(now, end='')
print()