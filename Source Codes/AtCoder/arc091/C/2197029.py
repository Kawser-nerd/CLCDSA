N, A, B = map(int, input().split())

if A + B - 1 > N or A * B < N:
    print('-1')
else:
    ans = list(range(1, B + 1)[::-1])
    if A > 1:
        x = (N - B) // (A - 1)
        y = (N - B) % (A - 1)
        st = B + 1
        for i in range(y):
            ans += list(range(st, st + x + 1)[::-1])
            st += x + 1
        for i in range(A - 1 - y):
            ans += list(range(st, st + x)[::-1])
            st += x

    print(' '.join(map(str, ans)))