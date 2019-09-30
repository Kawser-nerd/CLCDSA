N = int(input())
A = list(map(int, input().split()))

ans = 0
while True:
    if all(map(lambda x: x < N, A)):
        break

    temp = 0
    num = [0] * N

    for i in range(N):
        temp += A[i] // N
        num[i] = A[i] // N
        A[i] %= N

    ans += temp
    A = [a + temp - n for a, n in zip(A, num)]

print(ans)