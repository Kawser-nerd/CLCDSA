N, T = map(int, input().split())

ans = 0
A_tm1 = int(input())
for i in range(N-1):
    A_t = int(input())
    if A_t - A_tm1 < T:
        ans += A_t - A_tm1
    else:
        ans += T
    A_tm1 = A_t
ans += T

print(ans)