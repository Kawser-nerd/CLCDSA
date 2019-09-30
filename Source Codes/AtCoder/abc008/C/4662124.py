from math import ceil


def solve(C, i, N):
    divisor_sum = 0
    for j in range(N):
        if j == i:
            continue
        elif C[i] % C[j] == 0:
            divisor_sum += 1
    if divisor_sum != 0:
        return (ceil((divisor_sum+1)/2) / (divisor_sum+1))
    else:
        return 1


N = int(input())
C = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    ans += solve(C, i, N)
print(ans)