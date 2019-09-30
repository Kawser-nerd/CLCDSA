N, M = map(int, input().split(' '))
if N != 1 and M != 1:
    ans = N*M - (2*N + 2*M - 4)
else:
    if N == 1 and M == 1:
        ans = 1
    else:
        ans = N*M - 2

print(ans)