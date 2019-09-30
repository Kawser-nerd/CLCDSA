N = int(input())
src = []
for i in range(N):
    src += list(input())[::-1]
remain = src.count('.')
ans = now = 0
while remain:
    while src[now] == 'o':
        now += 1
    ans += 1
    remain -= src[now:now+N+1].count('.')
    now += N+1
print(ans)