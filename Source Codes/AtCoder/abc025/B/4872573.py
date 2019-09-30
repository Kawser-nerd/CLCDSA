N, A, B = map(int, input().split())
ans = 0
for i in range(N):
    s, d = input().split()
    d = int(d)
    if d < A:
        d = A
    elif d > B:
        d = B
    if s == 'East':
        ans += d
    else:
        ans -= d
if ans > 0:
    print('East' + ' ' + str(ans))
elif ans == 0:
    print(0)
elif ans < 0:
    print('West' + ' ' + str(abs(ans)))