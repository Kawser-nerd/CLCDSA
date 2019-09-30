# ?????

K = int(input())

if K == 1:
    print(1)
    print(1)
else:
    n = ((K + 3) // 4) * 2
    print(n)
    for r in range(n):
        line = []
        for c in range(n):
            if r % 2 == 0:
                t = (r + c) % n + 1
            else:
                t = n + (r + c) % n + 1
            if t > K:
                t -= n
            line.append(t)
        print(*line)