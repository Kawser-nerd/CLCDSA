tests = int(input())
for t in range(tests):
    n = int(input())
    a = list(map(int, input().split()))
    first = 0
    for i in range(n - 1):
        if a[i + 1] < a[i]:
            first += a[i] - a[i + 1]
    maxdiff = 0
    for i in range(n - 1):
        maxdiff = max(maxdiff, a[i] - a[i + 1])

    current, second = a[0], 0
    for i in range(1, len(a)):
        now = min(current, maxdiff)
        second += now
        current = a[i]

    print('Case #{}: {} {}'.format(t + 1, first, second))
