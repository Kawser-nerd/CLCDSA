N, A, B = map(int, input().split())
inputs = [int(input()) for _ in range(N)]


if (max(inputs) - min(inputs)) == 0:
    print(-1)
else:
    P = B / (max(inputs) - min(inputs))
    Q = A - P * sum(inputs) / N
    print(P, Q)