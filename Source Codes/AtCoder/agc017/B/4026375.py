N, A, B, C, D = [int(_) for _ in input().split()]
distance = abs(A - B)
for i in range(N):
    if -D * i + C * (N - 1 - i) <= distance <= -C * i + D * (N - 1 - i):
        print('YES')
        exit()
print('NO')