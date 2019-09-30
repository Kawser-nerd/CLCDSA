def inpl():
    return list(map(int, input().split()))


N, x = inpl()
A = inpl()

ans = 0

for i in range(1, N):
    if A[i - 1] + A[i] <= x:
        continue

    tmp = A[i - 1] + A[i] - x
    ans += tmp
    if tmp >= A[i]:
        A[i] = 0
    else:
        A[i] -= tmp
print(ans)