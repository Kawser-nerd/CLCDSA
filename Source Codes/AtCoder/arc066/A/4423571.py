def inpl():
    return list(map(int, input().split()))


N = int(input())

A = inpl()
A.sort()

if N % 2 == 1:
    a = 1
    if A[0] != 0:
        print(0)
        exit()
else:
    a = 0

ans = 1
for j, i in enumerate(range(a, N, 2)):
    if A[i] == A[i + 1] == 2 * (j + 1) - (a + 1) % 2:
        ans *= 2
    else:
        print(0)
        exit()
print(ans % (10**9 + 7))