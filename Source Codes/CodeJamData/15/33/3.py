from sys import stdin

def solve(tc):
    c, d, v = map(int, stdin.readline().split())
    coins = sorted(map(int, stdin.readline().split()))

    current = 0

    result = 0

    for coin in coins:
        while current + 1 < coin and current < v:
            result += 1
            current += (current + 1) * c
        if current + 1 >= coin:
            current += coin * c
    while current < v:
        current += (current + 1) * c
        result += 1

    print 'Case #%d: %d' % (tc, result)


if __name__ == '__main__':
    t = int(stdin.readline())
    for i in range(t):
        solve(i + 1)

