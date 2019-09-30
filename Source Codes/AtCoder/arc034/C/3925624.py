A, B = map(int, input().split())

C = {}
for i in range(B+1, A+1):
    y = i
    x = 2
    while x*x <= y:
        if y % x == 0:
            cnt = 0
            while y % x == 0:
                cnt += 1
                y //= x
            C[x] = C.get(x, 0) + cnt
        x += 1
    if y > 1:
        C[y] = C.get(y, 0) + 1

MOD = 10**9 + 7
ans = 1
for v in C.values():
    ans = (ans * (v+1)) % MOD
print(ans)