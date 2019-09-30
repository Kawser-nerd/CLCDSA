N, A, B = map(int, input().split())

ans = 0
for i in range(N):
    s, d = input().split()
    d = int(d)

    d = max(min(d, B), A)
    if s == 'West':
        d *= -1
    ans += d

if ans == 0:
    print(ans)
elif ans < 0:
    print('West', abs(ans))
else:
    print('East', ans)