def sum_digit(b, n):
    if n < b:
        return n
    return sum_digit(b, n // b) + n % b

N = int(input())
S = int(input())

if S > N:
    print(-1)
elif S == N:
    print(N + 1)
else:
    sqrt = int(pow(N, 0.5))
    for b in range(2, sqrt + 1):
        if sum_digit(b, N) == S:
            print(b)
            quit()
    for k in reversed(range(1, sqrt + 1)):
        if (N - S) % k == 0:
            b = (N - S) // k + 1
            if sum_digit(b, N) == S:
                print(b)
                quit()
    print(-1)