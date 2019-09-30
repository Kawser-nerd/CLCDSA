tests = int(input())

def solve(b, n, a):
    left = 0
    right = 2 * max(a) * n
    while left + 1 < right:
        c = (left + right) // 2

        started = 0
        for bi in a:
            started += c // bi + 1
        if started < n:
            left = c
        else:
            right = c

    started = 0
    for bi in a:
        started += left // bi + 1
    startedBefore = started
    now = []

    for i, bi in enumerate(a):
        if (left + 1) % bi == 0:
            started += 1
            now.append(i + 1)

    return now[n - 1 - startedBefore]

for t in range(tests):
    b, n = map(int, input().split())
    a = list(map(int, input().split()))
    print('Case #{}: {}'.format(t + 1, solve(b, n, a)))
