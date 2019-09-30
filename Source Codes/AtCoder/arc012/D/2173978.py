# seishin.py
N, T, mod = map(int, input().split())
P = [0]*(T+2)
for i in range(N):
    x, y = map(int, input().split())
    x = abs(x); y = abs(y)
    if T < x+y or (T - x - y) % 2 == 1:
        print(0)
        exit(0)
    m = (T - x - y) // 2
    P[1] -= 2
    P[x+m+1] += 1
    P[T-(x+m)+1] += 1
    P[m+1] += 1
    P[T-m+1] += 1
    P[T+1] -= 2
for i in range(1, T+2):
    P[i] += P[i-1]
P[1] = 0
for x in range(2, T+1):
    y = x; i = 2
    while i*i <= y:
        if y % i == 0:
            cnt = 0
            while y % i == 0:
                y //= i
                cnt += 1
            P[i] += P[x]*cnt
        i += 1
    if 1 < y < x:
        P[y] += P[x]
    if y < x:
        P[x] = 0
ans = 1
for x in range(2, T+1):
    if P[x]:
        ans = (ans * pow(x, P[x], mod)) % mod
print(ans)