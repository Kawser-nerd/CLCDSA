N, Q = map(int, input().split())
li = [0] * (N + 1)
for i in range(Q):
    l, r = map(int, input().split())
    li[l - 1] += 1
    li[r] -= 1
for i in range(N):
    li[i + 1] += li[i]
ans = ''
for n in li[:-1]:
    if n % 2 == 0:
        ans += '0'
    else:
        ans += '1'
print(ans)