N, A, B, C, D = map(int, input().split())

# ?????????????i??????
for i in range(N):
    dMin = -D * i + C * (N - 1 - i)
    dMax = -C * i + D * (N - 1 - i)
    if A + dMin <= B <= A + dMax:
        print('YES')
        break
else:
    print('NO')