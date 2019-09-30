T = int(input())

for t in range(1, T + 1):
    N = int(input())
    steps = 1
    current = 1
    L = len(str(N))

    while len(str(current)) != len(str(N)):
        K = len(str(current))
        if K == 1:
            current = 10
            steps = 10
        else:
            current = current * 10
            steps += 10 ** (K // 2) + 10 ** (K - K // 2) - 1

    if current != N and L > 1 and str(N)[-1] == '0':
        N -= 1
        steps += 1

    if L > 1:
        V = str(N)[:L // 2]
        V = V[::-1]
        if int(V) > 1:
            steps += int(V) + 1
            current = int(V[::-1] + '0' * (L - L // 2))
            current += 1
    steps += N - current
    print("Case #%d: %d" % (t, steps))
