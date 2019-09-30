N = int(input())
A = sorted([int(_) for _ in input().split()])


def comb(n, r):
    res = 1
    for i in range(n - r + 1, n + 1):
        res *= i
    for i in range(1, r):
        res //= i
    return res


x = A.pop()
N -= 1
for i in range(N):
    if A[i] > x // 2:
        break
if abs(A[i] - x / 2) < abs(A[i - 1] - x / 2):
    print(x, A[i])
else:
    print(x, A[i - 1])